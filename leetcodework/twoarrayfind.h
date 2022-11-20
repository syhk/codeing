// 题目：在二维数组中查找是否存在某个数字

#include "iostream"

class syhk {
 public:
  bool test1(int* ptr, int col, int row, int target);
};

/*
col 行数
row 列数
*/
bool syhk::test1(int* ptr, int columns, int rows, int target) {
  // int i = 1;
  // while (true) {
  //   if (ptr[row - 1] == target) return true;

  //   if (ptr[row - 1] > target) {
  //     row--;

  //   } else {
  //     i++;
  //     if (ptr[i * 4 - (row + 1)] == target) return true;
  //   }
  // }
  // return false;
  // ===========================================================
  bool found = false;
  if (ptr != nullptr && rows > 0 && columns > 0) {
    int row = 0;
    int column = columns - 1;
    while (row < rows && column >= 0) {
      if (ptr[row * columns + column] == target) {
        found = true;
        break;
      } else if (ptr[row * columns + column] > target)
        --column;
      else
        ++row;
    }
  }
  return found;
}