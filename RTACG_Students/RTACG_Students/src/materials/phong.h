#ifndef PHONGMATERIAL
#define PHONGMATERIAL

#include "material.h"

class Phong : public Material
{
public:
    Phong();
    Phong(Vector3D Kd_, Vector3D Ks_,  float    alpha_);

    Vector3D getReflectance(const Vector3D& n, const Vector3D& wo,
        const Vector3D& wi)const ;

    bool hasSpecular() const { return false; }
    bool hasTransmission() const { return false; }
    bool hasDiffuseOrGlossy() const { return true; }
    bool isEmissive() const { return false; }

    double getIndexOfRefraction() const;
    Vector3D getEmissiveRadiance() const;
    Vector3D getDiffuseReflectance() const;
    Vector3D ComputeReflectionDirection(const Vector3D& n, const Vector3D& wo) const;
    Vector3D ComputeTransmissionDirection(const Vector3D& n, const Vector3D& wo, const bool& inside) const;


private:
    Vector3D rho_d;
    Vector3D Ks;
    float    alpha;
    

};
#endif // MATERIAL