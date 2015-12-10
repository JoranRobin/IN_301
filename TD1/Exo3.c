#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mul_egypt(int x, int y, int r)
{
	if(x==0)
	{
		return 0;
	}
	if(x==1)
	{
		return y+r;
	}
	
	if(x%2==1)
	{
		printf("%d*%d+%d\n=",(x-1),y,y);
		return mul_egypt(x-1,y,y+r);
	}
	else
	{
		printf("%d*%d+%d\n=",x/2,2*y,r);
		return mul_egypt(x/2,2*y,r);
	}
}

//fonction principale
int main(){
	int x,y;
	x=23;y=87;
	printf("%d*%d\n=",x,y);
	printf("%d",mul_egypt(x,y,0));
}
