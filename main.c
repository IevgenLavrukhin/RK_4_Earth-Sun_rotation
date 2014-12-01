#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "elimination.h"


int main(int argc, char** argv)

{
//READ DATA FROM THE FILE FOR ARRAY A  AND B;
  int NN=0;
  FILE* fileA = fopen(argv[1], "r");
  FILE* fileB = fopen(argv[2], "r");
 
  while (fscanf(fileA, "%*f")!=EOF) NN++;
  rewind(fileA);
  
  int N = sqrt(NN);
  double  *dataA = malloc(NN*sizeof(double));
  double  *dataB = malloc(N*sizeof(double));

  for (int i=0; i<N*N; i++) fscanf(fileA, "%lf", &dataA[i]);
  for (int i=0; i<N; i++) fscanf(fileB, "%lf", &dataB[i]);

  fclose(fileA);
  fclose(fileB);

//print the coefficience from files:
//      for(int i=0; i<N*N; i++) printf ("%lf", dataA[i]);      
//      printf ("\n");
//      for(int i=0; i<N; i++) printf ("%lf", dataB[i]);
//      printf ("\n");
//      printf ("%d, %d \n", NN, N); 


//ARRAY OF RESULTS:
  double *x = malloc(N*sizeof(double));
  solve_system(dataA, N, dataB, x);

  for(int i=0; i<N; i++) printf("% 10.5f ", x[i]); printf("\n");


  return 0;
}


