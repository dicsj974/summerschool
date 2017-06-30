#include <stdio.h>
#include <omp.h>

int main(void)
{
    int var1 = 1, var2 = 2;
    int var3 = 5;



#pragma omp parallel firstprivate(var1, var2) shared(var3) // private, firstprivate or shared		
    /* TODO:
     *   Test the effect of different data sharing clauses here
     */
    {
        printf("Region 1: var1=%i, var2=%i\n", var1, var2);
        var1++;
        var2++;
    }
    printf("After region 1: var1=%i, var2=%i\n\n", var1, var2);

    return 0;
}
