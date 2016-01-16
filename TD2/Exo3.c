#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

struct element
{
	int val;
	struct element* suiv;
};

typedef struct element Element;
typedef Element* Liste;


Liste init_liste()
{
	return NULL;
}

int vide(Liste l)
{	
	return l == NULL;
}

void affiche_liste(Liste l)
{
	while(!vide(l))
	{
		printf("%d ", l -> val);
		l = l -> suiv;
	}
	printf("\n");
}

void libere_memoire(Liste l)
{
	if(!vide(l))
	{
		libere_memoire(l->suiv);
		free(l);
	}
}

Liste ajout_debut(Liste l, int valeur)
{
	Element *e;
	e = malloc(sizeof(Element));
	if(e == NULL)
	{
		exit(0);
	}
	else
	{
		e -> val = valeur;
		e -> suiv = l;
		return e;
	}
}

Liste ajout_fin(Liste l, int valeur)
{
	if(vide(l))
	{
		l = ajout_debut(l,valeur);
	}
	else
	{
		l -> suiv = ajout_fin(l -> suiv,valeur);
	}
	
	return l;
}

Liste remplit_liste(int n)
{
	int x;
	Liste l = init_liste();
	
	while(1)
	{
		x=alea_int(n);
		
		if(x==0)
		{
			return l;
		}
		else
		{
			l=ajout_debut(l,x);
		}
	}
	return l;
}

int est_triee(Liste l)
{
	if(vide(l) || vide(l -> suiv))
	{
		return 1;
	}
	if(l -> val > l -> suiv -> val)
	{
		return 0;
	}
	return est_triee(l -> suiv);
}

Liste ajout_triee(Liste l, int v)
{
	if(vide(l) || l -> val > v)
	{
		l = ajout_debut(l,v);
	}
	else
	{
		l -> suiv = ajout_triee(l -> suiv,v);
	}
	return l;
}

int nb_element(Liste l)
{
	if(vide(l))
	{
		return 0;
	}
	return 1 + nb_element(l -> suiv);
}

int recherche(Liste l, int e)
{
	if(vide(l))
	{
		return 0;
	}
	if(l -> val == e)
	{
		return 1;
	}
	return recherche(l->suiv,e);
}

Liste supprime(Liste l, int e)
{
	Liste ll;
	
	if(!vide(l))
	{
		if(l->val==e)
		{
			ll=l;
			l=l->suiv;
			free(ll);
		}
		else
		{
			l->suiv=supprime(l->suiv,e);
		}
	}
	return l;
}

Liste concatener(Liste l1,Liste l2)
{
	if(vide(l1))
	{
		return l2;
	}
	else
	{
		l1->suiv=concatener(l1->suiv,l2);
		return l1;
	}
}

Liste entrelacer(Liste l1,Liste l2)
{
	if(vide(l1))
	{
		return l2;
	}
	
	if(vide(l2))
	{
		return l1;
	}
	
	if(l1->val < l2->val)
	{
		l1->suiv=entrelacer(l1->suiv,l2);
		return l1;
	}
	else
	{
		l2->suiv=entrelacer(l1,l2->suiv);
		return l2;
	}
}

int main()
{
	int x,y,z,r,t;
	Liste l1=init_liste();
	Liste l2=init_liste();
	Liste l3;
	
	l1 = ajout_debut(l1,3);
	l1 = ajout_debut(l1,2);
	l1 = ajout_debut(l1,1);
	l1 = ajout_fin(l1,9);
	l1 = ajout_triee(l1,8);
	l1 = ajout_triee(l1,7);
	l1 = ajout_triee(l1,5);
	
	l2 = ajout_debut(l2,6);
	l2 = ajout_debut(l2,13);
	
	l3=remplit_liste(5);
	
	concatener(l1,l2);
	/*l = supprime(l1,2);*/
	
	x=nb_element(l1);
	y=nb_element(l2);
	z=nb_element(l3);
	r=recherche(l3,4);
	t=est_triee(l1);
	
	affiche_liste(l1);
	affiche_liste(l2);
	affiche_liste(l3);
	
	printf("nombre d'element Liste 1 :%d \n",x);
	printf("nombre d'element Liste 2 :%d \n",y);
	printf("nombre d'element Liste 3 :%d \n",z);
	
	printf("recherche du nombre 4 dans la liste 3 :%d \n",r);
	printf("Liste 1 triee:%d \n",t);
		
	return 0; 
}
