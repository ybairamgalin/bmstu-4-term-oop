#ifndef POINT2D_H
#define POINT2D_H

struct point2d
{
    double x;
    double y;
};

point2d *point2dCreate(double x, double y);
void point2dDelete(point2d &);

double point2dGetX(point2d &);
double point2dGetY(point2d &);

point2d mul(point2d &, double);
point2d add(point2d &, point2d &);

#endif // POINT2D_H
