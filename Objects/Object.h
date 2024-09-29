#ifndef Object_H
#define Object_H

#include "Vector.h"

class Object
{
protected:
    Vector position;
    Vector velocity;
    Vector acceleration;
    double mass;
    bool isStatic;

public:
    Object(Vector startPosition, double objectMass, bool objectStatic);
    
    virtual void Update(double deltaTime);

    virtual void ApplyForce(Vector force);
};

#endif
