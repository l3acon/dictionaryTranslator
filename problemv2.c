#include <stdio.h>
#include <time.h> 
#include <stddef.h>
#include <stdlib.h>

void filestuff(void)
{
  FILE *infile;
  FILE *ofile;
  
  char *buffer;
  long numbytes;
  char lookup[127] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,50,50,50,51 ,51 ,51 ,52 ,52 ,52 ,53 ,53 ,53 ,54 ,54 ,54 ,55 ,55 ,55 ,55 ,56 ,56 ,56 ,57 ,57, 57 ,57 ,91,92,93,94,95,96,50,50,50,51 ,51 ,51 ,52 ,52 ,52 ,53 ,53 ,53 ,54 ,54 ,54 ,55 ,55 ,55 ,55 ,56 ,56 ,56 ,57 ,57, 57 ,57 ,123,124,125,126,127};

  infile = fopen("words.txt", "r");
  ofile = fopen("numbers.txt", "w");
  
  if((infile == NULL) || (ofile == NULL))
      return 1;
   
  fseek(infile, 0L, SEEK_END);
  numbytes = ftell(infile);
 
  fseek(infile, 0L, SEEK_SET);

  buffer = (char*)calloc(numbytes, sizeof(char)); 
   
  if(buffer == NULL)
      return 1;
   
  fread(buffer, sizeof(char), numbytes, infile);
  fclose(infile);

  int i;
  for(i = 0; i<numbytes; i++)
  {
    buffer[i]=lookup[(int)buffer[i]];
  }
  
  fwrite(buffer, sizeof(buffer), numbytes, ofile);
  free(buffer);
  fclose(ofile);
} 

int main ()
{
  clock_t t;
  t = clock();
  filestuff();
  t = clock() - t;
  printf ("It took %d clicks\n",t);
  printf("(%f seconds assuming %ld clocks/sec)\n", ((float)t)/CLOCKS_PER_SEC,(long)CLOCKS_PER_SEC );

  return 0;
}

