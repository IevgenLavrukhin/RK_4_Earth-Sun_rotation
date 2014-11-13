#include <stdlib.h>

/************************************/

void integrate_rk2 (double *yold, int n, double t, double dt, double *ynew,
		void (*F)(double*, double, double*))
{
  double *deriv1 = (double*) malloc(n*sizeof(double));
  double *yhalf = (double*) malloc(n*sizeof(double));

  F(yold, t, deriv1);
  for (int i=0; i<n; ++i) yhalf[i] = yold[i]+deriv1[i]*dt/2;
  F(yhalf, t+dt/2, deriv1);
  for (int i=0; i<n; ++i) ynew[i]=yold[i]+deriv1[i]*dt;

  free(deriv1); 
  free(yhalf);
}



/***********************************/

void integrate_rk4 (double *yold, int n, double t, double dt, double *ynew,
		void (*F)(double*, double, double*))
{
  double *k1 = (double*) malloc(n*sizeof(double));
  double *k2 = (double*) malloc(n*sizeof(double));
  double *k3 = (double*) malloc(n*sizeof(double));
  double *k4 = (double*) malloc(n*sizeof(double));

  double *ystep = (double*) malloc(n*sizeof(double));

  //calculate k1
  F(yold, t, k1);

  //calculate k2
  for (int i=0; i<n; ++i) ystep[i] = yold[i]+k1[i]*dt/2;
  F(ystep, t+dt/2, k2);

  //calculate k3
  for (int i=0; i<n; ++i) ystep[i] = yold[i]+k2[i]*dt/2;
  F(ystep, t+dt/2, k3);

  //calculate k4
  for (int i=0; i<n; ++i) ystep[i] = yold[i]+k3[i]*dt;
  F(ystep, t+dt/2, k4);

  // the resulting solution of the problem
  for (int i=0; i<n; ++i) ynew[i]=yold[i]+(k1[i]+2*k2[i]+2*k3[i]+k4[i])* dt/6;
  
  free(k1);
  free(k2); 
  free(k3); 
  free(k4);  
  free(ystep);
}


