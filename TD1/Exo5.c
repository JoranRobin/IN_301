#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fonction principale
int main(){

int i,nb,test;
test=0;

printf("Entrez un nombre(different de 1 et 2) :");

if(scanf("%d",&nb) !=1)
{
	return -1;
}

for(i=2;i<nb;i++)
{
	if((nb%i)==0)
	{
		test=1;
	}
	if(!test)
	{
		printf("%d est un nombre premier\n",nb);
	}
	else
	{
		printf("%d n'est pas un nombre premier\n",nb);
	}

return 0; 

}
}
