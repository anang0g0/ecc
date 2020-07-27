char* reverse_string(char *str)
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


unsigned long b2s(BigInt a){
  BigInt c;
  char b[64]="",m1[]="0",m2[]="1",*end;
  int i,count=0;

  //a=strtoull("11001101111111110000000000",0,2,64);
  c=a;
  while(c>0){
    c=(c>>1);
    count++;
  }
    
  a.write(std::cout) << std::endl;
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
  reverse_string(b);
  printf("%s\n",b);
  a=strtoull(b,&end,2);
  printf("%llu\n",a);

  return a;
}

void main(){

  BigInt a="100000000000000000000011111111111111111111111111111111100000000000000000000000000000000000000000000000001";

  a=b2s(a);
  printf("%llu\n",a);
  
}
