#include <stdio.h>
#include "operation.h"
#include "cartesianplane.h"

void testing();
int main(){
  testing();
  return 0;
}
void testing(){
  printf("Creating points\n");

  Point A;
  A.x = 1;
  A.y = 1;

  Point B;
  B.x = 2;
  B.y = 2;

  Point C;
  C.x = 3;
  C.y = 3;

  Point D;
  D.x = 2;
  D.y = 3;

  Point E;
  E.x = 3;
  E.y = 2;

  Point K[4] = {A,B,C,D};
  int i=0;
  for(; i<4; i++)
    printf("{%lf %lf} ", K[i].x,K[i].y);
  printf("distance A->B: %lf", distance(D,B));

  printf("\ndeterminant direction: ");
  Point L[3] = {C, D, E};
  for(i =0; i<3; i++)
    printf("%d ", determinant(A,B,L[i]));
  
  Quadrilateral Q;
  Q.number_side=4;
  Q.A = A;
  Q.B = D;
  Q.C = C;
  Q.D = E;
  printf("\nis_convex: %d\narea: %lf",is_convex(Q),area(Q));
  Point F;
  F.x = 2;
  F.y = 2.5;
  Q.D = B;
  printf("\nis_convex: %d\narea: %lf",is_convex(Q),area(Q));
  Q.D = F;
  printf("\nis_convex: %d\narea: %lf",is_convex(Q),area(Q));
  Q.A.x =0;
  Q.A.y =0;

  Q.B.x =0;
  Q.B.y =1;

  Q.C.x =1;
  Q.C.y =1;

  Q.D.x =1;
  Q.D.y =0;
  printf("\nis_convex: %d\narea: %.11lf",is_convex(Q),area(Q));
}
