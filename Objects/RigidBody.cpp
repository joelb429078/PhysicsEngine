#include "Object.h"

class  RigidBody: public Object
{
private:
    double rotation;
    double angularVelocity;
    double torque;
    double momentOfInertia;
public:
     RigidBody(Vector startPosition, double objectMass, bool objectStatic, double inertia, double rotation) : Object(startPosition,  objectMass,  objectStatic){
        this->rotation = rotation;
        angularVelocity = 0;
        torque = 0;
        momentOfInertia = inertia;
     }
     void ApplyTorque(double torque){
        this->torque += torque;
     }
     void Update(double deltaTime) override{
        Object::Update(deltaTime);
        angularVelocity += (torque / momentOfInertia) * deltaTime;
        rotation += angularVelocity * deltaTime;
     }
};