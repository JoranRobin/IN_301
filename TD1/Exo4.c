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
	int n;
	printf("donnez un entier:\n");
	scanf("%d",&n);
	
	printf("La somme numerique est %f \n",somme(n));
	return(1);
}
