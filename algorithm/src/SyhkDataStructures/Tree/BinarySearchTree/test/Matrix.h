#ifndef MATRIX_H
#define MATRIX_H
#include "vector"
using std::vector;

template <typename T>
class matrix {
 public:
  matrix(int rows, int cols) : array(rows) {
    for (int i = 0; i < rows; i++) array[i].resize(cols);
  }

  const vector<T>& operator[](int row) const { return array[row]; }

  vector<T>& operator[](int row) { return array[row]; }

  int numrows() const { return array.size(); }

  int numcols() const { return numrows() ? array[0].size() : 0; }

 private:
  vector<vector<T>> array;
};

#endif