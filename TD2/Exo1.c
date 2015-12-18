#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permuter(int* a,int* b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void reinitPointeur(int* *p)
{
	*p=NULL;
}


//fonction principale
int main()
{
	int a=2,b=3,*d;
	char tab[10];
	char (*p)[10]=&tab;
	int e=1;
	d=&e;
	reinitPointeur(&d);
	
	
printf("char: %d octets\n",sizeof(char));
printf("int: %d octets\n",sizeof(int));
printf("double: %d octets\n",sizeof(double));
printf("char*: %d octets\n",sizeof(char*));
printf("void*: %d octets\n",sizeof(void*));
printf("int*: %d octets\n",sizeof(int*));
printf("double*: %d octets\n",sizeof(double*));
printf("int**: %d octets\n",sizeof(int**));
printf("int[10]: %d octets\n",sizeof(int[10]));
printf("char[7][3]: %d octets\n",sizeof(char[7][3]));

printf("tab[0]: %d octets\n",sizeof(tab[0]));
printf("&tab[0]: %d octets\n",sizeof(&tab[0]));
printf("*&tab: %d octets\n",sizeof(*&tab));
printf("*&tab[0]: %d octets\n",sizeof(*&tab[0]));

printf("p: %d octets\n",sizeof(p));
printf("*p: %d octets\n",sizeof(*p));
printf("(*p)[2]: %d octets\n",sizeof((*p)[2]));
printf("&(*p)[2]: %d octets\n",sizeof(&(*p)[2]));

printf("a=%d et b=%d\n",a,b);
permuter(&a,&b);
printf("a=%d et b=%d\n",a,b);

printf("d=%p",d);
 
} 
