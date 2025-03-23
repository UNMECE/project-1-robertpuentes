#include <iostream>
#include <iomanip>
#include "capacitor.h"

int main(){
	double dt = 1e-5;
	int steps = 50000;
	double Cvalue = 1e-3;
	double I0 = 0.01;
	double R = 1000.0;
	double V0 = 5.0;
	
	_capacitor cap;
	cap.C = Cvalue;
	cap.time = new double[steps];
	cap.voltage = new double[steps];
	cap.current = new double[steps];

	solvecurrent(cap, I0, dt, steps);
	std::cout << "constant current results:\n";
	std::cout << "time\t\tvoltage\t\tcurrent\n";
	for (int n = 0; n < 5; n++){
		std::cout << std::fixed << std::setprecision(6)	<< cap.time[n] << "\t" << cap.voltage[n] << "\t" << cap.current [n] << "\n";
	}
	std::cout << "...\n\n";
	
	for(int n = 0; n < steps; n++){
		cap.time[n] = 0.0;
		cap.voltage[n] = 0.0;
		cap.current[n] = 0.0;
	}
	
	solvevoltage(cap, V0, R, dt, steps);	
	std::cout << "constant voltage results:\n";
	std::cout << "time\t\tvoltage\t\tcurrent\n";
	for(int n = 0; n < 5; n++){	
		std::cout << std::fixed << std::setprecision(6) << cap.time[n] << "\t" << cap.voltage[n] << "\t\t" << cap.current[n] << "\n";
	}
	std::cout << "...\n\n";

	delete[] cap.time;
	delete[] cap.current;
	delete[] cap.voltage;
	
	return 0;
}
