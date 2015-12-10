#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double somme(int n)
{
	double i;
	double s=0;
	
	for(i=1;i<n+1;i++)
	{
		s+=1/(i*i);
	}
	return s;
}

//fonction principale
int main(){
	int n,i;
	double k,c;
	k=0.000001;
	c=1;
	
	while(c>k)
	{
		printf("donnez un entier positif:\n");
		scanf("%d",&n);
		c=somme(n+1)-somme(n);
		printf("\nSomme(%d+1)-Somme (%d) vaut :%f \n",n,n,c);
		printf("La precision vaut:%f \n",k);
	}
	
	printf("La somme de %d vaut :%f",n,somme(n));
	
}
	
	
