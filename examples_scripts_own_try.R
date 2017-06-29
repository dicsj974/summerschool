
myfirstvector <- c(4, 10000, -5.7, pi)

charvec <- c("cat", "dog", "ant")
charvec[2]  #Extracting elements

mean(myfirstvector, trim=0.3) #Trim removes magnitude different values

charvec <- c("cat", "dog", "ant", "ant", "dog", "ant")
summary(charvec)
animals <- factor(charvec)
summary(animals)

data(iris)
summary(iris)



library(ggplot2)  #Help -> Cheatsheets -> Data visualization with ggplot
ggplot(iris)+ 
    geom_point(aes(Sepal.Width, Sepal.Length, col=Species))

ggplot(iris)+ 
  geom_point(aes(Sepal.Width, Sepal.Length, col=Species))+
  geom_smooth(aes(Sepal.Width,Sepal.Length,col=Species))

library(tidyr)
library(dplyr)
tidycards <- cards %>%
  gather(key = "week",value = "N", starts_with("week"))

tidycards <- tidycards %>%
  
  separate(col = week,into = c("foo","week"),sep = 4) %>%
  select(-foo) %>%
  mutate(week=as.numeric(week))
ggplot(tidycards)+
  geom_line(aes(x=week,y=N,color=card))
  


tidycards <- tidycards %>%
  group_by(week) %>%
  mutate(weekrank=rank(N)) %>%
  ungroup()


# find the mean number of each card over the weeks
tidycards %>%
  group_by(card) %>%
  summarise(meanN=mean(N)) %>%
  ungroup()


