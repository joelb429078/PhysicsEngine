#ifndef RigidBody_H
#define RigidBody_H

#include "Object.h"

class RigidBody : public Object
{
private:
    double rotation;
    double angularVelocity;
    double torque;
    double momentOfInertia;

public:
    RigidBody(Vector startPosition, double objectMass, bool objectStatic, double inertia, double rotation);
    void ApplyTorque(double torque);
    void Update(double deltaTime) override;
};

#endif 
