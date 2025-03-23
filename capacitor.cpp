#include "capacitor.h" 
#include <iostream>
#include <cmath>

void solvecurrent(_capacitor &cap, double I0, double dt, int steps){
	cap.voltage[0] = 0.0;
	cap.current[0] = I0;
	cap.time[0] = 0.0;

	for(int n=0; n < steps - 1; n++){
		cap.time[n+1] = cap.time[n] + dt;
		cap.voltage[n+1] = cap.voltage[n] + (I0 / cap.C) * dt;
		cap.current[n+1] = I0;
	}
}

void solvevoltage(_capacitor &cap, double V0, double R, double dt, int steps){
	cap.voltage[0] = 0.0;
        cap.current[0] = V0 / R;
        cap.time[0] = 0.0;

	for(int n = 0; n < steps - 1; n++){
		cap.time[n+1] = cap.time[n] + dt;
		double vnext = cap.voltage[n] + dt * (1 / (R*cap.C)) * (V0 - cap.voltage[n]);
		cap.voltage[n+1] = vnext;
		cap.current[n+1] = (V0 - vnext) / R;
	}
}
