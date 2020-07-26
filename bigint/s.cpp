#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "bigint.hpp"
#include <assert.h>
#include "bigint.h"

int u2b(unsigned long long int decimal){

  /* 変数の宣言 */
  int binary = 0;
  unsigned long long int base = 1;
 
  /* 10進数の入力 */
  printf("10進数 = ");

 
  /* 10進数を2進数に変換 */
  while(decimal>0){
    binary = binary + ( decimal % 2 ) * base;
    decimal = decimal / 2;
    base = base * 10;
  }
 
  /* 変換した2進数の出力 */
  printf(" 2進数 = %d\n", binary);
 
  return 0;
}


//char buf[100];
void itoa(char buf[1000],unsigned long long int x){

  
  sprintf(buf, "%llu", x);
  printf("s=%s\n",buf);

  //  exit(1);
}


void reverse_string(char *str)
{
    char temp;
    int len = strlen(str) - 1;
    int i;
    int k = len;

    for(i = 0; i < len; i++)
    {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
        k--;

        /* As 2 characters are changing place for each cycle of the loop
           only traverse half the array of characters */
        if(k == (len / 2))
        {
            break;
        }
    }
}


void b2s(BigInt a){
  BigInt c,x;
  char b[1000]="",m1[]="0",m2[]="1",*end,e[100];
  int i,count=0;
  unsigned long long int w={0};
  
  //a=strtoull("11001101111111110000000000",0,2,64);
  c=a;
  while(c>0){
    c=(c>>1);
    count++;
  }
  printf("count=%d\n",count);
  
  a.write(std::cout) << std::endl;
  //  exit(1);
  for(i=0;i<count;i++){
    if(a%2==0){
      strcat(b,m1);
      if(a>0)
	a=(a>>1);
    } else {
      if(a%2==1){
	strcat(b,m2);
	if(a>0)
	  a=(a>>1);
      }
    }
  }
    //if(i%64==0){
      reverse_string(b);
      itoa(e,strtoull(b,&end,2));
      printf("b'=%s\n",b);
      x=e;
      //x=w[0];
      x.write(std::cout) << std::endl;
      //printf("%llu\n",w[0]);
      //memset(b,'\0',sizeof(b));

  //}
  //printf("%llu\n",w[0]);

  printf("b=%s\n",b);  
  itoa(e,strtoull(b,&end,2));
  x=e;
  //x=w[0];
  x.write(std::cout) << std::endl;
 

  exit(1);
  
  return;
}


int main(){

  BigInt a="100000000000000000000011111111111111111111111111111111100000000000000000000000000000000000000000000000001";

  // exit(1);
  
  b2s(a);
  //printf("%llu\n",a);

  return 0;
}
