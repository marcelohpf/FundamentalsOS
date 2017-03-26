#ifndef OPERATION
#define OPERATION
#include "cartesianplane.h"

/* Determine if any quadrilateral is or not a convex polygon 
 * to determine that, was used this referece: 
 * https://github.com/edsomjr/TEP/blob/master/Geometria_Computacional/Polygon.md#pol%C3%ADgonos-c%C3%B4ncavos-e-convexos
 * based in orientation between a line and point
 * 1 - is convex
 * 0 - is not convex
 * -1 - is not a quadrilateral object
 * */
int is_convex(Quadrilateral quadrilateral);

/* Determine the area of any convex polygon using
 * the reference used to implement the formula was:
 * https://github.com/edsomjr/TEP/blob/master/Geometria_Computacional/Polygon.md#per%C3%ADmetro-e-%C3%A1rea
 * */
double area(Quadrilateral quadrilateral);


/* Determine a that return the orientation of a point and line
 * | Px Py 1|
 * | Qx Qy 1|
 * | Rx Ry 1|
 * 0 - point in the line
 * 1 - clockwise
 * -1 - counter-clockwise
 *  reference: https://github.com/edsomjr/TEP/blob/master/Geometria_Computacional/Retas.md#orienta%C3%A7%C3%A3o-entre-ponto-e-reta
 */
int determinant(Point A, Point B, Point C);

/* define a comparation to float point.
 * In c file define a error aceptation as ER = 1 x 10^-12
 * 1 - equals
 * 0 - different
 */
int equals(double a, double b);
#endif
