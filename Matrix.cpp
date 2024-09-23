#include "Matrix.h"
#include <iostream>
#include <cmath>
class Matrix {
    /* (1,2,3,4) =  (1 2)
                    (3 4)*/
  private:
    double first_entry;
    double second_entry;
    double third_entry;
    double fourth_entry; 
  public:
    Matrix(double entry1, double entry2, double entry3, double entry4) : 
      first_entry(entry1), second_entry(entry2), third_entry(entry3), fourth_entry(entry4){};

    double get_first_value() const {
      return first_entry;
    }

    double get_second_value() const {
      return second_entry;
    }

    double get_third_value() const {
      return third_entry;
    }

    double get_fourth_value() const {
      return fourth_entry;
    }

    void matrix_add(const Matrix& added_matrix){
        first_entry += added_matrix.get_first_value();
        second_entry += added_matrix.get_second_value();
        third_entry += added_matrix.get_third_value();
        fourth_entry += added_matrix.get_fourth_value();
    }

    void matrix_mulp(const Matrix& mulp_matrix){
        //mulp_matrix is multiplied from the left
        first_entry = (mulp_matrix.get_first_value()*first_entry) + (mulp_matrix.get_second_value()*third_entry);
        second_entry = (mulp_matrix.get_first_value()*second_entry) + (mulp_matrix.get_second_value()*fourth_entry);
        third_entry = (mulp_matrix.get_third_value()*first_entry) + (mulp_matrix.get_fourth_value()*third_entry);
        fourth_entry = (mulp_matrix.get_third_value()*second_entry) + (mulp_matrix.get_fourth_value()*fourth_entry);
    }


};
