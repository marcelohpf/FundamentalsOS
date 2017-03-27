#include "io_operation.h"
#include "operation.h"
#include <stdlib.h>

int menu(){
  int keep = 1;
  while(keep) {
    Quadrilateral quadrilateral = in_quadrilateral();
    geometry_output(quadrilateral);
    printf("0 -> exit\n1 -> continue\n");
    scanf("%d",&keep);
    printf("\n");
  }
  printf("exiting\n");
  return keep;
}
Quadrilateral in_quadrilateral(){
  Quadrilateral quadrilateral;
  quadrilateral.number_side = 4;

  quadrilateral.A = in_point();
  quadrilateral.B = in_point();
  quadrilateral.C = in_point();
  quadrilateral.D = in_point();
  return quadrilateral;
}

Point in_point(){
  Point point;
  int read = 0;
  int count =0;
  while(!read){
    double x,y; // Values of cordinates (x,y) of cartesian plan
    read = (scanf("%lf %lf",&x,&y) == 2);
    if(!read){
      perror("X and Y coordinates not readed");
    } else {
      point.x = x;
      point.y = y;
    }
    if(count++ > 10){
      perror("Aborting, too many attemps");
      exit(0);
    }

  }

  return point;
}

void geometry_output(Quadrilateral quadrilateral){
  show_points_distance(quadrilateral);
  convex_output(quadrilateral);
  area_output(quadrilateral);
}

void area_output(Quadrilateral quadrilateral){
  if(is_convex(quadrilateral) == 1){
    double area_quadrilateral = area(quadrilateral);
    printf("Área: %.12lf\n", area_quadrilateral);
  }
}

int convex_output(Quadrilateral quadrilateral){
  int convex = is_convex(quadrilateral);
  if(convex == 1){
    printf("Quadrilatero convexo\n");
  } else if(convex == -1){
    printf("Não é um quadrilatero\n");
  } else {
    printf("Não é convexo\n");
  }
  return convex;
}


void show_points_distance(Quadrilateral quadrilateral){
  Point points[5] = {quadrilateral.A, quadrilateral.B, quadrilateral.C,
                    quadrilateral.D, quadrilateral.A};
  char point_letter[5] = {'A','B','C','D','A'};
  int point = 0;
  printf("Distancias entre os pontos:\n");
  for(point = 0; point < 4; point ++){
    printf("\t%c->%c: %.12lf\n", point_letter[point],
            point_letter[point+1], 
            distance(points[point], 
            points[point+1]));
  }
}
