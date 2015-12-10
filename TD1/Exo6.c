#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sommediviseur(int n)
{
	int i,sommed;
	sommed=0;
	
	for(i=1;i<=(n/2);i++)
	{
		if((n%i)==0)
		{
			sommed+=1;
		}
	}
	return sommed; 
}

//fonction principale
int main()
{
	int a,b;
	
printf("Entrez Un Nombre:");
scanf("%d",&a);

printf("Entrez Un Nombre:");
scanf("%d",&b);
	
		if(sommediviseur(a)==b && sommediviseur(b)==a)
	{
		printf("%d et %d sont des nombres amis",a,b);
	}
	else
	{
		printf("%d et %d ne sont pas des nombres amis",a,b);
	}
}
