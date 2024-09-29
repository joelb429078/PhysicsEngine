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
    Object(Vector startPosition, double objectMass, bool objectStatic){
        position = startPosition;
        velocity = Vector(0,0);
        acceleration = Vector(0,0);
        mass = objectMass;
        isStatic = objectStatic;
    }

    virtual void Update(double deltaTime){
        Vector deltaAcceleration = Vector(acceleration.get_x_value() * deltaTime, acceleration.get_y_value() * deltaTime);
        velocity.vector_add(deltaAcceleration);

        Vector deltaVelocity = Vector(velocity.get_x_value() * deltaTime, velocity.get_y_value() * deltaTime);
        position.vector_add(deltaVelocity);
    }

    virtual void ApplyForce(Vector force){
        force.scalar_mulp(1/mass);
        acceleration.vector_add(force);
    }
};

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

