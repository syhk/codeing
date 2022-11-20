#include "Matrix.h"
#include "iostream"
#include "list"
#include "vector"

using std::list;

int main() {
  matrix<float> mx(2, 3);

  std::cout << mx.numcols() << std::endl;

  return 0;
}
