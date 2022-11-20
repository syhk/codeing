#include <time.h>

#include <array>
#include <tuple>

#include "ctime"
#include "iostream"
#include "random"
#include "vector"

// 随机数种子
std::default_random_engine e(time(0));
// 最好 O(nlogn) 最坏O(n方)
using namespace std;
//  quick sort   （快速排序) O(nlogn)
//  实现思路： 轴点元素： 本质逐渐将每一个元素都转换成轴点元素 ;  递归
class quick {
 public:
  void quicksort(vector<int> &vec, int length) {
    // 刚开始大方向从右向左扫描
    // 轴点构造 : 备份轴点
    //  从 end 向 begin 扫描；
    // if end>begin  end-- ;
    // end<=begin  begin=end(覆盖);  相等也交换扫描方向
    // begin++ 交换扫描方向（交替进行） 从 begin 向 end 扫描
    // 重复以上步骤
    //  循环条件  ： begin != end
    //   将 备份的轴点元素赋值给 begin/end
    sort(0, length);
  }
  quick(vector<int> &vec) : vec(vec) {}
  void printvec() {
    for (auto i = vec.cbegin(); i != vec.cend(); i++) {
      cout << *i << '\t';
    }
  }

 private:
  int pivotIndex(int begin, int end);
  void sort(int begin, int end);
  vector<int> vec;
};
int main() {
  vector<int> vec = {23, 43, 5, 65, 56, 78, 45, 243, 65, -45};
  quick q(vec);
  q.quicksort(vec, vec.size());
  q.printvec();
}
int cmp(int x, int y) { return x - y; }
void swap(int &x, int &y) {
  int t = x;
  x = y;
  y = x;
}
void quick::sort(int begin, int end) {
  if (end - begin < 2) return;
  // 确定轴点位置
  int mid = pivotIndex(begin, end);
  //  对子序列进行快速排序
  sort(begin, mid);
  sort(mid + 1, end);
}
// 构造出 begin,end 范围的轴点元素
int quick::pivotIndex(int begin, int end) {
  // 随机选择一个元素跟轴点元素进行交换，避免出现最坏情况
  uniform_int_distribution<int> u(begin, end - 1);
  // 随机一个数字 和轴点元素交换也就是 begin
  //   cout << "随机取的数为 ： " << u(e) << endl;
  int random = u(e);
  swap(begin, random);
  // 备份 begin 位置的元素
  int v = vec[begin];
  //   cout << "begin ： = " << v << endl;
  // end 指向最后一个元素
  end--;
  while (begin < end) {
    // 需要交替执行 , 交换方向
    while (begin < end) {
      // 从右到左
      if (cmp(v, vec[end]) < 0) {  // begin < end 右边元素 > 轴点元素   这里加上
        // = 会导致最坏情况出现的频率增大
        end--;
      } else {  //  右边元素  <=  轴点元素
        vec[begin++] = vec[end];
        break;
      }
    }
    while (begin < end) {
      // 从左到右
      if (cmp(v, vec[begin]) > 0) {  // 左边元素 <  轴点元素   这里加上 =
        // 会导致最坏情况出现的频率增大
        begin++;
      } else {  // 左边元素 > 轴点元素
        vec[end--] = vec[begin];
        break;
      }
    }
  }
  // 将轴点元素放入最终位置
  vec[begin] = v;
  return begin;
}