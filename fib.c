#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bigint.h"

#define MAX_INT_DIGITS 10
#define MAX_LONG_DIGITS 20

/*this function calculates the fibonacci sequence*/
int main(int argc, char** argv)
{
   printf("WARNING: Calculating large numbers of iterations can take a long time (> 10 minutes).\n");
   printf("The output file can also grow very large. The output file for 100,000 iterations is ~1GB.\n");
   printf("This program will use ~100%% CPU time during calculation.\n");
   printf("The program does not check for errors while calculating.\n");
   printf("If an error occurs during calculation, the operation of this program is undefined.\n");
   /*this function uses the following method to calculate the fibonacci sequence:
   
   a = 1, b = 1
   loop:
      c = a + b  //c[i] = c[i - 1] + c[i - 2]
      a = b //c[i - 2] = c[i - 1]
      b = c //c[i - 1] = c[i]
   in each loop, this seuence adds the two numbers together and takes the summands and
   their result, and moves them down the sequence. This sequence does not requre storage
   of any more than the last two numbers in the sequence.*/



   //the user is asked to press a key at the end of the program.
   //The read statement at the end has to store the result somewhere,
   //so it's put in here.
   char temp = 'a';


   //create 3 bigints: 2 for the summands, and one for the result
   bigint* a = newnumc("1");
   bigint* b = newnumc("1");
   bigint* c = newnumc("0");

   //get how many iterations? the user wants
   int size = 0;

   if(argc == 2)
   {
      size = atoi(argv[1]);
   }
   else if(argc == 4)
   {
      a = newnumc(argv[1]);
      b = newnumc(argv[2]);
      size = atoi(argv[3]);
   }
   else
   {
      printf("How many iterations do you want? ");
      scanf("%i", &size);
   }


   char* fname = (char*)malloc(9 + MAX_INT_DIGITS + MAX_LONG_DIGITS + 1);
   sprintf(fname, "fib-%i-%i.txt", size, time(NULL));
   FILE *file = fopen(fname, "w");

   //print the first two iterations of the fibonacci sequence
   if(size == 1)
   {
      fprint(a, file);
   }
   else if(size >= 2)
   {
      fprint(a, file);
      fprint(b, file);
   }


   //the program prints out the first two iterations separate from the rest
   size -= 2;


   //loop for the required number of iterations
   int i = 0;
   while(i < size)
   {
      //add the summands together and store the result in c
      add(a, b, c);
      //print the result
      fprint(c, file);

      //move b and c down the sequence
      //see description at the top for more information
      numcpy(a, b);
      numcpy(b, c);

      i++;
   }

   //clear a, b, and the result
   delnum(a);
   delnum(b);
   delnum(c);

   fflush(file);
   fclose(file);
   free(fname);

   return 0;
}
