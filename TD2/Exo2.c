#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int alea(int n)

	//int nombre;
	//srand(time(NULL));
	//nombre=rand()%(n+1);
	//return nombre;

	float alea_float()
	{
	static int init_alea = 1;
	if (init_alea) srand(getpid());
	init_alea = 0;
	return (float)rand() / (float)RAND_MAX;
	}

int alea_int(int N) 
{
	 return (int)(N*alea_float()); 
}

struct tableau{
	int taille;
	int tab[100];
	
};


typedef struct tableau TABLEAU;
TABLEAU t1;

TABLEAU init_tableau()
{
	int i;
	
	t1.taille=10;
	t1.tab[t1.taille];
	printf("Les %d valeurs du tableau sont: ",t1.taille);
	
	for(i=0;i<t1.taille;i++)
	{
	t1.tab[i]=alea_int(20);
	printf("%d ",t1.tab[i]);
	
}
}

int produit_tableau()
{
	int i;
	int produit;
	produit=1;
	
	for(i=0;i<t1.taille;i++)
	{
		produit*=t1.tab[i];
	}
	return produit;
}
int min_tableau()
{
	int i,min;
	min=t1.tab[0];
	
	for(i=0;i<t1.taille;i++)
	{
		if(t1.tab[i]<min)
		{
			min=t1.tab[i];
		}
	}
	return min;
}

TABLEAU decal_tableau()
{
	int i;
	printf("\nDecalage de 1 case a droite des valeurs du Tableau: ");
	
	for(i=0;i<t1.taille-1;i++) 
	{	
		t1.tab[i]=t1.tab[i+1];
		printf("%d ",t1.tab[i]);
	} 
}

//fonction principale
int main()
{
	int n;
	TABLEAU t1;
	printf("structure tableau: %d octets\n",sizeof(TABLEAU));
	n=alea_int(100);
	printf("n=%d\n",n);
	t1=init_tableau();
	printf("\nLe produit des valeurs du tableau = %d",produit_tableau());
	printf("\nLa valeur minimale du tableau = %d",min_tableau(t1));
	t1=decal_tableau();
} 
