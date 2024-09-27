#include "../Vector.cpp"
#include "../Object.cpp"

class Camera
{
    private:
        Vector position;
        float zoom;
        float zoomDelta;
        Object* target;
    public:
        Camera(){
            position = Vector();
            zoom = 1;
            zoomDelta = 0.2;
            target = nullptr;
    }

    void Move(Vector delta){
        position.vector_add(delta);
    }

    void Zoom(float factor){
        zoom += zoomDelta * factor;
    }

    void SetTarget(Object& target){
        this->target = &target;
    }

    void ResetTarget(){
        target = nullptr;
    }

    Vector GetPosition(){
        if(target != nullptr){
            position = target->GetPosition();
        }
        return position;
    }

    float GetZoom(){
        return zoom;
    }
};
