#include 'io_operation.h'

Point in_point(){
  Point point;
  int read = 0;
  while(!read){
    double x,y; // Values of cordinates (x,y) of cartesian plan
    read = (scanf("%lf %lf",&x,&y) == 2);
    if(!read){
      perror("X and Y coordinates not readed");
    } else {
      point.x = x;
      point.y = y;
    }
  }


  return point;
}

Quadrilateral in_quadrilateral(){
  Quadrilateral quadrilateral;

  quadrilateral.A = in_point();
  quadrilateral.B = in_point();
  quadrilateral.C = in_point();
  quadrilateral.D = in_point();
  return quadrilateral;
}



