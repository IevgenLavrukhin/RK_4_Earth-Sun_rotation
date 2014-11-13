void integrate_rk4 (double *yold, int n, double t, double dt, double *ynew, void (*F)(double*, double, double*));

void integrate_rk2 (double *yold, int n, double t, double dt, double *ynew, void (*F)(double*, double, double*));

