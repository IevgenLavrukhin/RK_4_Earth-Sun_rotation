#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integrator.h"

#define NBODY 2
double mass[NBODY];

void F(double *y, double t, double *res)	
{

  double G = 6.67428e-11;
  
  for(int i=0; i<2*NBODY; ++i) res[i] = y[2*NBODY+i];

  for(int i=0; i<NBODY; ++i)
  {
    res[2*NBODY+2*i+0]=0;
    res[2*NBODY+2*i+1]=0;

    for(int j=0; j < NBODY; ++j)
    if(j!=i)
    {
     double r[2] = { y[j*2]-y[i*2], y[j*2+1]-y[i*2+1]};
     double d = sqrt(r[0]*r[0]+r[1]*r[1]);

     res[2*NBODY+2*i+0]+=G*mass[j]*r[0]/pow(d,3);
     res[2*NBODY+2*i+1]+=G*mass[j]*r[1]/pow(d,3);

    }
  }	
}


int main(int argc, char** argv)

{

  double y[4*NBODY] = {1.52098e11, 0, -456775, 0, 0, 29296, 0, -0.087908};
  double t = 0;
  double dt = atof(argv[1]);
  double tstop = atof(argv[2]);;
  mass[0] = 5.9736e24;
  mass[1] = 1.9891e30;
 
   double mom[2]={0,0};
   double mtot=0;
   for(int i=0; i<NBODY; ++i)
   {
   mom[0]+=mass[i]*y[2*NBODY+2*i+0];
   mom[1]+=mass[i]*y[2*NBODY+2*i+1];
   mtot += mass[i];
   }
   for(int i=0; i<NBODY; ++i)
   {
   y[2*NBODY+2*i+0] -= mom[0]/mtot;
   y[2*NBODY+2*i+1] -= mom[1]/mtot;
   }

        printf("%6.3f ", t); for(int i=0; i<4*NBODY; ++i) printf ("%.15e ", y[i]); printf ("\n");

  int count =0;

	for (; t<tstop-dt/2; t+=dt)
	{
    count++;
		double ynew[4*NBODY];
		integrate_rk4(y, 4*NBODY, t, dt, ynew, F);
		if (count%100 ==0) {
        printf("%6.3f ", t); 
        for(int i=0; i<4*NBODY; ++i) printf ("%.15e ", ynew[i]); 
        printf ("\n");
      }
		 for (int i=0; i < 4*NBODY; ++i) y[i]=ynew[i];
	}
return 0;
}


