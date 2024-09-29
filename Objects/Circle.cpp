#include "RigidBody.h";

class Circle: public RigidBody
{
private:
    double radius;
public:
    Circle(Vector startPosition, double objectMass, bool objectStatic, double inertia, double rotation, double objectRadius) : RigidBody(startPosition, objectMass, objectStatic, inertia, rotation){
        radius = objectRadius;
    }

    double getRadius(){
        return radius;
    }

    void Draw(){
        // Draw circle
    }

    bool CheckCollision(Circle* otherCircle){
        Vector distanceVector = Vector(position.get_x_value() - otherCircle->position.get_x_value(), position.get_y_value() - otherCircle->position.get_y_value());
        double distance = distanceVector.length();
        return distance <= radius + otherCircle->radius;
    }

    void Update(double deltaTime) override{
        RigidBody::Update(deltaTime);
        Draw();
    }
};