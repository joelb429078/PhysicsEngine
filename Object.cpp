#include "Vector.cpp"

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

    Vector GetPosition(){
        return position;
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



