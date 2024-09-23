#include <iostream>
#include <cmath>
using namespace std;

class Vector {
  private:
    double x_value;
    double y_value;

  public:
    Vector(double x, double y) : x_value(x), y_value(y) {}

    double get_x_value() const {
      return x_value;
    }

    double get_y_value() const {
      return y_value;
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
}
