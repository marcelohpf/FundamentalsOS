#ifndef IO_CARTESIAN
#define IO_CARTESIAN
#include "cartesianplane.h"
#include <stdio.h>

/* receive pair of double values and return a point */
Point in_point();

/* receive a set of 4 points to create a quadrilateral polygon */
Quadrilateral in_quadrilateral();

/* The main program output, show points distances, is the polygon is or not 
 * convex and if is, show the area
 * */
void geometry_output(Quadrilateral quadrilateral);

/* show if the quadrilatero is a convex or not convex polygon 
 * return the result of is_convex function 
 * */
int convex_output(Quadrilateral quadrilateral);

/* show in standard output the value of area if is a convex polygon */
void area_output(Quadrilateral quadrilateral);

/* show distance of the point following the clockwise direction */
void show_points_distance(Quadrilateral quadrilateral);

#endif
