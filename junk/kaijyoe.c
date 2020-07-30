#include <stdio.h>

int kaijoe(){

  int stack[1000],j,i,n,m,l,x,count;
  
  
  i=1;stack[0]=1;n=0;l=0;count=0;
  scanf("%d",&x);
  
  for (i=1;i<x+1;i++)
    {l=n+1;
      for(j=0;j < n+1;j++)
	stack[j]=stack[j]*i;
      
      j=-1;
      for (j=0;j<l;j++)
	{
	  if (stack[j] > 9999)
	    {
	      m=stack[j]/10000;
	      if (j==n)
		{n++;
		  stack[j+1]=0;
		}
	      stack[j+1]=stack[j+1]+m;
	      stack[j]=stack[j]%10000;
	    }
	}
    }
  printf("%d\n",++n);
  while (--n >= 0)
    {
      printf("%4d ",stack[n]);
      if (++count == 10)
	{
	  printf("\n");
	  count=0;
	}
    }
  printf("\n");

  return 0;
}

//mul2()


int main()
{

  kaijoe();
  
  return 0;
  
  }


