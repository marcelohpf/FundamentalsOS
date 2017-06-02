#include "sin.h"

const int m = 19;
const int n = 90;

double arc_sin(double rads){
  double sum = rads;
  int i;
  for(i = 1; i < n; i++) {
    double term1 = fatt(i*2 -1)/fatt(i*2);
    double term2 = elevate(rads, i*2+1)/(i*2+1);
    sum += (term1*term2);
  }
  return sum;
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
double fatt(int n){
  double result = 1.0;
  for(int i=n; i>0; i-=2) result *= i;
  return result;
}

double fat(int n){
  double result = 1.0;
  for(int i=n; i> 0; i--) result *= i;
  return result;
}
