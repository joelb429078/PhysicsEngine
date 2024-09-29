#ifndef Rectangle_H
#define Rectangle_H

#include "RigidBody.h"

class Rectangle : public RigidBody
{
private:
    double width;
    double height;

public:
    Rectangle(Vector startPosition, double objectMass, bool objectStatic, double inertia, double rotation, double objectWidth, double objectHeight);
    double getWidth();
    double getHeight();
    void Draw();
    void Update(double deltaTime) override;
};

#endif
