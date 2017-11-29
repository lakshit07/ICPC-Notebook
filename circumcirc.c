#include <stdio.h>
#include <math.h>
#define EPS 1e-9
struct point {double x,y;};
typedef struct point point;
point points[500];

int circumCircle(point p1,point p2,point p3,point *ctr,double *rsq){             //gives us ctr-center of circumcircle and rsq-square of radius
  double a = p2.x - p1.x, b = p2.y - p1.y;
  double c = p3.x - p1.x, d = p3.y - p1.y;
  double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < EPS) return 0;
 
  (*ctr).x = (d*e - b*f) / g;
  (*ctr).y = (a*f - c*e) / g;
  *rsq =(p1.x-(*ctr).x)*(p1.x-(*ctr).x)+(p1.y-(*ctr).y)*(p1.y-(*ctr).y);
  return 1; }

 
