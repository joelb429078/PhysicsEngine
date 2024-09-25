#include "Vector.h"

class Object
{
protected:
    Vector position;
    Vector velocity;
    Vector acceleration;
    float mass;
    bool isStatic;
public:
    Object(Vector startPosition, float objectMass, bool objectStatic){
        position = startPosition;
        velocity = Vector(0,0);
        acceleration = Vector(0,0);
        mass = objectMass;
        isStatic = objectStatic;
    }

    virtual void Update(float deltaTime){
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
    float rotation;
    float angularVelocity;
    float torque;
    float momentOfInertia;
public:
     RigidBody(Vector startPosition, float objectMass, bool objectStatic, float inertia, float rotation) : Object(startPosition,  objectMass,  objectStatic){
        this->rotation = rotation;
        angularVelocity = 0;
        torque = 0;
        momentOfInertia = inertia;
     }
     void ApplyTorque(float torque){
        this->torque += torque;
     }
     void Update(float deltaTime) override{
        Object::Update(deltaTime);
        angularVelocity += (torque / momentOfInertia) * deltaTime;
        rotation += angularVelocity * deltaTime;
     }
};


class Circle: public RigidBody
{
private:
    float radius;
public:
    Circle(Vector startPosition, float objectMass, bool objectStatic, float inertia, float rotation, float objectRadius) : RigidBody(startPosition, objectMass, objectStatic, inertia, rotation){
        radius = objectRadius;
    }
    void Draw(){
        // Draw circle
    }

    bool CheckCollision(Circle* otherCircle){
        Vector distanceVector = Vector(position.get_x_value() - otherCircle->position.get_x_value(), position.get_y_value() - otherCircle->position.get_y_value());
        float distance = distanceVector.length();
        return distance <= radius + otherCircle->radius;
    }

    void Update(float deltaTime) override{
        RigidBody::Update(deltaTime);
        Draw();
    }
};


class Rectangle: public RigidBody
{
private:
    float width;
    float height;
public:
    Rectangle(Vector startPosition, float objectMass, bool objectStatic, float inertia, float rotation, float objectWidth, float objectHeight) : RigidBody(startPosition, objectMass, objectStatic, inertia, rotation){
        width = objectWidth;
        height = objectHeight;
    }
    void Draw(){
        // Draw rectangle
    }

    void Update(float deltaTime) override{
        RigidBody::Update(deltaTime);
        Draw();
    }
};

