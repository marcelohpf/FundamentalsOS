#include <math.h>
#include "operation.h"
#include "cartesianplane.h"
#define ER 1e-12

int is_convex(Quadrilateral quadrilateral){
    // Calculate each direction to determine the orientation of line and point
    int abc = determinant(quadrilateral.A, quadrilateral.B, quadrilateral.C);
    int bcd = determinant(quadrilateral.B, quadrilateral.C, quadrilateral.D);
    int cda = determinant(quadrilateral.C, quadrilateral.D, quadrilateral.A);
    int dab = determinant(quadrilateral.D, quadrilateral.A, quadrilateral.B);
    int convex = 0;
    // check if have 0 in directions (not a quadrilateral)
    if( (abc*bcd*cda*dab) ){
      convex = (abc > 0) && (bcd > 0) && (cda > 0) && (dab > 0);
    }else{
      convex = -1;
    }
    return convex;
}

int determinant(Point A, Point B, Point C){

    double value = (A.x * B.y + A.y * C.x + B.x * C.y) - (C.x * B.y + C.y * A.x + B.x * A.y);

    int answer = 0;
    if(value < 0){
      answer = 1;
    }else if(value > 0){
      answer = -1;
    } 
    return answer;
}

double area(Quadrilateral quadrilateral){
  double area = 0.0;
  if(is_convex(quadrilateral) == 1){
      Point points[5] = {quadrilateral.A, quadrilateral.B, quadrilateral.C, quadrilateral.D, quadrilateral.A};
      int point = 0;
      for(point = 0; point < quadrilateral.number_side; point++){
        area += points[point].x * points[point+1].y;
        area -= points[point+1].x * points[point].y;
      }
      area = fabs(area) * 0.5;
  } else {
    area = -1.0;
  }

  return area;
}

double distance(Point A, Point B){
  return hypot(A.x-B.x, A.y-B.y);
}

int equals(double a, double b){
  return fabs(a-b) < ER;
}
