#ifndef Vector_H
#define Vector_H
#include <iostream>
#include <cmath>
#include "Matrix.h"
using namespace std;

class Vector {
  private:
    double x_value;
    double y_value;

  public:
    Vector();
    Vector(double x, double y);

    double get_x_value() const ;

    double get_y_value() const ;

    void vector_add(const Vector& added_vector) ;

    void scalar_mulp(double scalar) ;

    void vector_subtract(const Vector& subtracted_vector) ;

    double dot_product(const Vector& dotted_vector) const ;

    double length() const ;

    void normalise() ;

    void matrix_mulp(const Matrix& mulp_matrix);
    
    void rotate(double degrees);
};
#endif;
