#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "Vector.h"
using namespace std;

class Vector {
  private:
    double x_value;
    double y_value;

  public:
    Vector() : x_value(0), y_value(0) {}
    Vector(double x, double y) : x_value(x), y_value(y) {}

    double get_x_value() const {
      return x_value;
    }

    double get_y_value() const {
      return y_value;
    }

    // Overloading + operator for vector addition
    Vector operator+(const Vector& other) const {
      return Vector(x_value + other.x_value, y_value + other.y_value);
    }

    // Overloading - operator for vector subtraction
    Vector operator-(const Vector& other) const {
      return Vector(x_value - other.x_value, y_value - other.y_value);
    }

    // Overloading * operator for dot product (vector * vector)
    double operator*(const Vector& other) const {
      return (x_value * other.x_value + y_value * other.y_value);
    }

    // Overloading * operator for scalar multiplication (vector * scalar)
    Vector operator*(double scalar) const {
      return Vector(x_value * scalar, y_value * scalar);
    }

    // Overloading * operator for scalar multiplication (scalar * vector)
    friend Vector operator*(double scalar, const Vector& vec) {
      return Vector(vec.x_value * scalar, vec.y_value * scalar);
    }

    void vector_add(const Vector& added_vector) {
      x_value += added_vector.get_x_value();
      y_value += added_vector.get_y_value();
    }

    void scalar_mulp(double scalar) {
      x_value *= scalar;
      y_value *= scalar;
    }

    void vector_subtract(const Vector& subtracted_vector) {
      x_value -= subtracted_vector.get_x_value();
      y_value -= subtracted_vector.get_y_value();
    }

    double dot_product(const Vector& dotted_vector) const {
      return (x_value * dotted_vector.get_x_value() + y_value * dotted_vector.get_y_value());
    }

    double length() const {
      return sqrt(pow(x_value, 2) + pow(y_value, 2));
    }

    void normalise() {
      double len = length();
      if (len != 0) {
        scalar_mulp(1 / len);
      }
    }

    void matrix_mulp(const Matrix& mulp_matrix)
    {
      x_value = (x_value * mulp_matrix.get_first_value()) +(y_value * mulp_matrix.get_second_value());
      y_value = (x_value * mulp_matrix.get_third_value()) +(y_value * mulp_matrix.get_fourth_value());
    }


    void rotate(double degrees){
      //anti-clockwise rotation
      Matrix rot_matrix(cos(M_PI*degrees/180),sin(M_PI*degrees/180),
                        -sin(M_PI*degrees/180),cos(M_PI*degrees/180));
      matrix_mulp(rot_matrix);
    }
};
