#include "RigidBody.h"

class Rectangle: public RigidBody
{
private:
    double width;
    double height;
public:
    Rectangle(Vector startPosition, double objectMass, bool objectStatic, double inertia, double rotation, double objectWidth, double objectHeight) : RigidBody(startPosition, objectMass, objectStatic, inertia, rotation){
        width = objectWidth;
        height = objectHeight;
    }

    double getWidth(){
        return width;
    }

    double getHeight(){
        return height;
    }

    void Draw(){
        // Draw rectangle
    }

    void Update(double deltaTime) {
        RigidBody::Update(deltaTime);
        Draw();
    }
};