#include "sin.h"

const int m = 19;

double arc_sin(double rads){
	return rads;
}

double sin(double rads){
	double sum = rads;
	int k = -1, i;
	for(i = 3; i <= m; i += 2) {
		sum += k * (elevate(rads, i) / fat(i));
		k *= -1;
	}
	return sum;
}

double elevate(double x, int n){
	int i;
	double number = 1.0;
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