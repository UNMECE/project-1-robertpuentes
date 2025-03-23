#ifndef CAPACITOR_H
#define CAPACITOR_H

struct _capacitor {
	double *time;
	double *voltage;
	double *current;
	double C;
};

void solvecurrent(_capacitor &cap, double I0, double dt, int steps);
void solvevoltage(_capacitor &cap, double V0, double R, double dt, int steps);

#endif
