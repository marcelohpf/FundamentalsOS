#ifndef CARTESIANPLANE
#define CARTESIANPLANE

typedef struct point{
  double x;
  double y;
} Point;

typedef struct quadrilateral{
  Point A;
  Point B;
  Point C;
  Point D;
  int number_side;
} Quadrilateral;

#endif
