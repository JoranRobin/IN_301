#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fonction principale
int main(){
int i,h,m,s;
i=200;

m=i/60;
s=i%60;
h=m/60;
m=m%60;


printf("%d secondes correpond a %d heures %d minutes et %d secondes",i,h,m,s);
}


