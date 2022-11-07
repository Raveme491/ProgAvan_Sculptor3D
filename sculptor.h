#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxel.h"

class Sculptor
{
private:
    Voxel ***v; // 3D matrix
    int nx, ny, nz; // Dimensions
    float lado, r, g, b; // Current drawing color
    float a;
public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void alocacao();
    void liberacao();
    void setColor(float _r, float _g, float _b, float _a);
    void putVoxel(int x0, int y0, int z0);
    void cutVoxel(int x0, int y0, int z0);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
