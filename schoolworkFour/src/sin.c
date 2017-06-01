#include "sin.h"
#include <math.h>

double arc_sin(double rads){
	double root = sqrt(1 - npow(rads, 2));
	double angle = arc_tan(rads / root);
  	return angle;
}

double sin(double rads){
	rads = rads - (npow(rads, 3) / fat(3)) + (npow(rads, 5) / fat(5)) - (npow(rads, 7) / fat(7)) + (npow(rads, 9) / fat(9));
  	return rads;
}

double arc_tan(double rads){
	double angle = rads - (npow(rads, 3) / 3.0) + (npow(rads, 5) / 5.0);
	return angle;
}

long int npow(int x, int n){
	int i, number = 1;
	for(i = 0; i < n; i++) {
		number *= x;
	}
	return number;
}

long int fat(int n){
	if(n >= 1)
		return n * fat(n - 1);
	else
		return 1;
}