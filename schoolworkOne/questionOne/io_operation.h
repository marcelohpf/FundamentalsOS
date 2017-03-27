#ifndef IO_CARTESIAN
#define IO_CARTESIAN
#include 'cartesianplane.h'
#include <stdio.h>

/* receive pair of double values and return a point */
Point in_point();

/* receive a set of 4 points to create a quadrilateral polygon */
Quadrilateral in_quadrilateral();

/* show if the quadrilatero is a convex or not convex polygon */
void convex_out(Quadrilateral quadrilateral);
#endif
