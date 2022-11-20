// Red Black Tree
/*
红黑树必备五条性质：
- 节点是 RED 或者 BLACK
- 根节点是 BLACK
- 叶子节点都是 BLACK
- RED 节点的子节点都是 BLACK
  从根节点到叶子节点的所有路径上不能有 2 个连续的 RED 节点
- 从任一节点到叶子节点的所有路径都包含相同数目的 BLACK 节点
B 树 (平特的多路搜索树)
> 多用于文件系统，数据库的实现
特点：
- 1 个节点可以存储超过 2 个元素，可以拥有超过 2 个子节点
- m 阶 B 树的性质（m>=2)
- 假设元素个数为 x
 - 根节点：  1 <= x <= m - 1
- B树和二叉树在逻辑上是等价的
- N 阶B树每个节点最多存储 N - 1 个数据
n 代合并的超级节点，最多拥有 2的n次方个子节点
B树新添加元素，必定是添加到叶子节点
*/
// 红黑树和4阶B树具有等价性
// BLACK 节点与它的 RED 子节点融合在一起，形成一个 B 树节点
// 红黑树的 BLACK 节点个数与 4 阶B数的节点总数相等
#include "../AVLTree/AVLtree.h"
enum Color { RED = false, BLACK = true };
class Node : public AVLNode {
 public:
  //  construction
  Node() = default;
  Node(int element)
      : element(element), left(nullptr), right(nullptr), parent(nullptr) {}
  Node(int element, Node* left, Node* right, Node* parent)
      : element(element), left(left), right(right), parent(parent) {}
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  int element = 0;
  int depth = 0;
  int color = Color::BLACK;
  // 封装一些函数
  bool issLeaf() { return left == nullptr && right == nullptr; }
  bool hasTwoChildren() { return left != nullptr && right != nullptr; }
  bool isLeftChild() { return parent != nullptr && this == parent->left; }
  bool isRightChild() { return parent != nullptr && this == parent->right; }
  //   返回兄弟节点
  Node* sibling() {
    if (isLeftChild()) {
      return parent->right;
    }
    if (isRightChild()) {
      return parent->left;
    }
    return nullptr;
  }
};
// 一些辅助函数
class RBTree {
 public:
  // 添加: 一共有 12 种情况
  void add(int x) {
    Node* node = new Node(x);
    cout << "添加的元素为：" << node->element << '\t' << node->color << endl;
    afterAdd(node);
  }
  // 遍历
  void ProT(Node* root) {
    if (root == nullptr) return;
    cout << root->element << '\t' << root->color << endl;
    ProT(root->left);
    ProT(root->right);
  }

 private:
  void afterAdd(Node* node);
  void afterRemove(Node* node, Node* replacement);
  Node* color(Node* node, bool color);
  Node* red(Node* node);
  Node* black(Node* node);
  bool colorOf(Node* node);
  bool isBlack(Node* node);
  bool isRed(Node* node);
  // 情况总结：
  /*
  LL\RR
  判定条件： uncle 是否 RED
  1.parent 染成 BLACK ,grand 染成 RED
  2.grand 进行单旋操作
  LL:右旋转
  RR:左旋转
  LR\RL
  判定条件：uncle 不是RED
  1.自己染成 BLACK，grand当成 RED
  2.进行双旋操作
  LR:parent 左旋转，grand 右旋转
  RL:parent 右旋转，grand 左旋转
  LL
  判定条件： uncle 是 RED
  1.parent、uncle 染成 BLACK
  2.grand 向上合并
  染成RED，当做是新添加的节点进行处理
  RL
  判定条件：uncle 是RED
  parent、uncle 染成 BLACK
  grand 向上合并
  染成 RED,当做是新添加的节点进行处理
  */
};
inline void RBTree::afterAdd(Node* node) {
  cout << "afteradd 添加的元素为： " << node->element << '\t' << node->color
       << endl;
  Node* parent = node->parent;
  // 添加的是根节点 ,或者上溢到根节点
  if (parent == nullptr) {
    black(node);
    return;
  }
  // 如果父节点是黑色直接返回
  if (isBlack(parent)) return;
  // uncle 节点判断
  Node* uncle = parent->sibling();
  // 祖父节点
  Node* grand = parent->parent;
  if (isRed(uncle))  // 叔父节点是RED,B 树节点上溢
  {
    black(parent);
    black(uncle);
    // 把祖父节点当做是新添加的节点
    red(grand);
    afterAdd(grand);
    return;
  }
  // 叔父节点不是 RED
  if (parent->isLeftChild()) {  // L
    red(grand);
    if (node->isLeftChild()) {  // LL
      black(parent);
    } else {  // LR
      black(node);
      leftRotate(parent);
    }
    rightRotate(grand);
  } else {                      // R
    if (node->isLeftChild()) {  // RL
      black(node);
      rightRotate(parent);

    } else {  // RR
      black(parent);
    }
    leftRotate(grand);
  }
}
// 删除之后 ,维护红黑树结构
// node 当前正要删除的节点， replacement 用以取代 node 的子节点
inline void RBTree::afterRemove(Node* node, Node* replacement) {
  // 在 B 树中，最后真正被删除的元素都在叶子节点中

  // 1. 删除 RED 节点；不会破坏红黑树的结构
  if (isRed(node)) return;

  // 2.删除 BLACK 节点
  // 有 3 种情况
  // a： 拥有 2 个 RED 子节点的 BLACK
  // 的节点(不可以被直接删除，会找它的子节点替代删除) b: 拥有 1 个 RED 子节点的
  // BLACK 节点
  //  判定条件： 用以替代的子节点是 RED
  if (isRed(replacement)) {
    black(replacement);
    return;
  }

  Node* parent = node->parent;
  //  删除的是根节点
  if (parent == nullptr) return;

  // 删除的是黑色叶子节点，会导致 B树节点下溢
  //  如果 sibling 至少有 1 个 RED 子节点
  // 进行旋转操作
  // 旋转之后的中心节点继承 parent 的颜色
  // 旋转之后的左右节点染为 BLACK

  // 以判断兄弟开头
  // 判断被删除的 node 是左还是右
  bool left = parent->left == nullptr;
  Node* sibling = left ? parent->right : parent->left;

  if (left)  // 被删除的节点在左边,兄弟节点在右边
  {
  } else {  // 被删除的节点在右边,兄弟节点在左边

    if (isRed(sibling)) {  // 兄弟节点是红色
      black(sibling);
      red(parent);
      rightRotate(parent);
      // 更换兄弟
      sibling = parent->left;
    }
    // 兄弟节点是黑色
    if (isBlack(sibling->left) &&
        isBlack(sibling->right)) {  // 兄弟节点没有一个红色子节点
      bool parentBlack = isBlack(parent);
      black(parent);
      red(sibling);
      if (parentBlack) {
        afterRemove(parent, nullptr);
      }
    } else {  // 兄弟节点至少有一个红色子节点
      // 兄弟节点的左边是黑色,兄弟要先旋转
      if (isBlack(sibling->left)) {
        leftRotate(sibling);
      }
      color(sibling, colorOf(parent));
      black(sibling->left);
      black(parent);
      rightRotate(parent);
    }
  }
  //  未写完
}
// 染色
inline Node* RBTree::color(Node* node, bool color) {
  if (node == nullptr) return node;
  node->color = color;
  return node;
}
// 把结点染成 red
inline Node* RBTree::red(Node* node) { return color(node, Color::RED); }
// 把结点染成 black
inline Node* RBTree::black(Node* node) { return color(node, Color::BLACK); }
// 判断某个节点是什么颜色
inline bool RBTree::colorOf(Node* node) {
  // 所有叶子结点默认都是黑色，也就是抽象的那些节点
  return node == nullptr ? Color::BLACK : node->color;
}
// 是否是 black
inline bool RBTree::isBlack(Node* node) { return node->color == Color::BLACK; }
// 是否是 red
inline bool RBTree::isRed(Node* node) { return node->color == Color::RED; }
// M 阶 B 树每个结点至多存储 M-1 个数据
// 红黑树的平衡标准:没有一条路径会大于其他路径的 2 倍
