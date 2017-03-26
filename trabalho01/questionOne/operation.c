#include 'operation.h'
#include 'cartesianplane.h'

int is_convex(Quadrilateral quadrilateral){
    // Calculate each direction to determine the orientation of line and point
    int abc = determinant(quadrilateral.A, quadrilateral.B, quadrilateral.C);
    int bcd = determinant(quadrilateral.B, quadrilateral.C, quadrilateral.D);
    int cda = determinant(quadrilateral.C, quadrilateral.D, quadrilateral.A);
    int dab = determinant(quadrilateral.D, quadrilateral.A, quadrilateral.B);

    return (abc > 0) && (bcd > 0) && (cda > 0) && (dab > 0);
}

int determinant(Point A, Point B, Point C){

    double deteCminant = (A.x * B.y + A.y * C.x + B.x * C.y) - (C.x * B.y + C.y * A.x + B.x * A.y);

    int answer = 0;
    if(determinant < 0){
      answer = 1;
    }else if(determinant > 0){
      answer = -1;
    } else {
      answer = 0;
    }

    return answer;
}


