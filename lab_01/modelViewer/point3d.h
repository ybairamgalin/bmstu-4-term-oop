#ifndef POINT3D_H
#define POINT3D_H

struct point3d
{
    double x;
    double y;
    double z;
};

point3d point3dInit(const double x, const double y,
                const double z);
point3d *point3dCreate(const double x, const double y,
                       const double z);
void point3dDelete(point3d &point);

void point3dSetX(point3d &point, const double x);
double point3dGetX(const point3d &point);

void point3dSetY(point3d &point, const double y);
double point3dGetY(const point3d &point);

void point3dSetZ(point3d &point, const double z);
double point3dGetZ(const point3d &point);

#endif // POINT3D_H
