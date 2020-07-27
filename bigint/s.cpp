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


void b2s(BigInt a,char b[1000]){
  BigInt c,x,tmp;
  char m1[]="0",m2[]="1",*end,e[100],*s;
  int i,count=0,n=0,nn=0;
  //char d[10]={'0','1','2','3','4','5','6','7','8','9'};
  
  //a=strtoull("11001101111111110000000000",0,2,64);
  c=a;
  while(c>0){
    c=(c/10);
    count++;
  }
  printf("count=%d\n",count);
  
  a.write(std::cout) << std::endl;
  //  exit(1);
  //for(i=0;i<count;i++){
  while(a>0){
    if(a%10==0){
      strcat(b,"0");
      a=a/10;
    }
    if(a%10==1){
      strcat(b,"1");
      a=a/10;
    }
    if(a%10==2){
      strcat(b,"2");
      a=a/10;
    }
    if(a%10==3){
      strcat(b,"3");
      a=a/10;
    }
    if(a%10==4){
      strcat(b,"4");
      a=a/10;
    }
    if(a%10==5){
      strcat(b,"5");
      a=a/10;
    }
    if(a%10==6){
      strcat(b,"6");
      a=a/10;
    }
    if(a%10==7){
      strcat(b,"7");
      a=a/10;
    }
    if(a%10==8){
      strcat(b,"8");
      a=a/10;
    }
    if(a%10==9){
      strcat(b,"9");
      a=a/10;
    }
    /*
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
    */
  }
  reverse_string(b);
    printf("b'=%s\n",b);
    //    exit(1);

    /*
    //    x+=b;
   if(i%64==0){
     reverse_string(b);
      itoa(e,strtoull(b,&end,2));
      printf("e=%s\n",e);
      tmp=e;
      x+=(tmp<<n);


      printf("b'=%s\n",b);
      x.write(std::cout) << std::endl;
      printf("len=%u\n",n);
      //x=(x<<n);

      n+=strlen(b);
      //printf("%llu\n",w[0]);
      //   memset(b,'\0',sizeof(b));

   }
   
  }
  

  reverse_string(b);
  itoa(e,strtoull(b,&end,2));
  printf("e=%s\n",e);
  tmp=e;
  x+=(tmp<<n);
  
  printf("b'=%s\n",b);
  x.write(std::cout) << std::endl;
  printf("len=%u\n",n);
  //x=(x<<n);
  
  n+=strlen(b);
  //printf("%llu\n",w[0]);
  memset(b,'\0',sizeof(b));

  x.write(std::cout) << std::endl;
    */

  return;
}


int main(){

  BigInt a="100000000000000000000011111111111111111111111111111111100000000000000000000000000000000000000000000000001";
  BigInt b[7],c;
  char buf[1000]="",str[10]="0b";
  int i;

  
  b[0]="1";
  b[1]="10546867377348280320";
  b[2]="12359296661107663004";
  b[3]="11594155628782290091";
  b[4]="15757484524022726084";
  b[5]="14267836963702871875";
  b[6]="23408381";

  //  std::cout << a%10 << std::endl;
  
     //  <<(64+64+64+5+65+64))+(
  c=b[0]+(b[1]<<1)+(b[2]<<65);
    //b[0]+(b[1]<<1)+(b[2]<<65)+(b[3]<<(65+64))+(b[4]<<(65+64+64))+(b[5]<<(65+64+64+64))+(b[6]<<(65+64+64+64+64));
  //455977564877012062125955178607639789569

  c.write(std::cout) << std::endl;
  //exit(1);



  b2s(a,buf);

    std::cout << "\naa\n\n";
  
  std::cout << buf << std::endl;

  c=buf;
  c.write(std::cout) << std::endl;
  
  //printf("%llu\n",a);

  return 0;
}
