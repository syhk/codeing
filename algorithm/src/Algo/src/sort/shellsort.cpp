#include <utility>
#include "iostream"
#include "vector"
using namespace std;
/**
1959 年由 唐纳德.希尔 提出
希尔排序把序列看作一上矩阵，分成 m 列，逐列进行排序
矩阵的列数取决于步长序列(step sequence)
不同的步长序列执行效率也不同
希尔本人给的是 ： n/2的k次方 eg: n=16 时步长序列为： 1,2,4,8
希尔排序底层是使用插入排序来对每一列进行排序
*/
int cmp(int x, int y) { return x - y; }
class Shell {
 public:
  void shellsort();
  //   Shell(vector<int> vec, vector<int> step) : vec(vec), stepSequence(step)
  //   {}
  Shell() = default;

  void shellStepSequence();
  void print() {
    cout << "原序列为：" << endl;
    for (auto i = vec.cbegin(); i != vec.cend(); i++) {
      cout << *i << '\t';
    }
    cout << "步长序列为：" << endl;
    for (auto i = stepSequence.cbegin(); i != stepSequence.cend(); i++) {
      cout << *i << '\t';
    }
  }
 private:
  void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = x;
  }
  void sort(int step);
  vector<int> vec = {23, 23, 5, 56, 7, 8, 13, 45, 86, 342};
  // 步长序列
  vector<int> stepSequence;
};

void Shell::shellsort() {
  for (int i : stepSequence) {
    sort(i);
  }
}
void Shell::sort(int step) {
  // 有多少列就排序多少次
  for (int col = 0; col < step; col++) {  // 对 col 列进行排序

    // 对 [0,size) 范围的元素进行插入排序
    for (int begin = col + begin; begin < vec.size(); begin += step) {
      int cur = begin;
      int temp = cur - step;
      while (cur > 0 && cmp(cur, temp) < 0) {
        swap(cur, temp);
        cur -= step;
      }
    }
  }
}
void Shell::shellStepSequence() {
  int step = vec.size();
  while ((step >>= 1) > 0) {
    stepSequence.push_back(step);
  }
}
int main() {
  Shell shell;
  shell.shellStepSequence();
  shell.shellsort();
  shell.print();
} 