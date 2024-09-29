#ifndef Circle_H
#define Circle_H

#include "RigidBody.h"

class Circle : public RigidBody
{
private:
    double radius;

public:
    Circle(Vector startPosition, double objectMass, bool objectStatic, double inertia, double rotation, double objectRadius);

    double getRadius();

    void Draw();

    bool CheckCollision(Circle* otherCircle);
    
    void Update(double deltaTime) override;
};

#endif
