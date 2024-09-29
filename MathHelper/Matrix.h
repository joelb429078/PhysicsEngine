#ifndef Matrix_h
#define Matrix_h
#include <cmath>

using namespace std;


class Matrix {
    /* (1,2,3,4) =  (1 2)
                    (3 4)*/
  private:
    double first_entry;
    double second_entry;
    double third_entry;
    double fourth_entry; 
  public:
    Matrix(double entry1, double entry2, double entry3, double entry4);

    double get_first_value() const;

    double get_second_value() const;

    double get_third_value() const;

    double get_fourth_value() const;

    void matrix_add(const Matrix& added_matrix);

    void matrix_mulp(const Matrix& mulp_matrix);

};
#endif;