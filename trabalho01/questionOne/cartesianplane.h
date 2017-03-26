#IFNDEF CARTESIANPLANE
#DEF CARTESIANPLANE

typedef struct point{
  double x;
  double y;
} Point;

typedef struct quadrilateral{
  Point A;
  Point B;
  Point C;
  Point D;
} Quadrilateral;

#ENDIF
