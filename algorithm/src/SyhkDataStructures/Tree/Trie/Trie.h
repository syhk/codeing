#ifndef __TRIE_H_
#define __TRIE_H_
#include <string>
class Trie {
 private:
  //  0 表示 false , 1 是 true
  enum Color { Blue = 0 /*不是*/, RED = 1 /*是*/ };
  class Node {
   public:
    Node() = default;
    Node(char c, Node* children) : c(c), children(children) {}
    char c;
    Node* children = nullptr;
    bool word = Color::Blue;  // 是否为单词的结尾（是否为一个单词）
  };

  int size = 0;
  Node* root = new Node();

  Node* findnode(std::string str) {
    keyCheck(str);
    Node* node = root;
    int len = str.size();
    for (int i = 0; i < len; i++) {
      if (root->children->c != str[i]) {
        return nullptr;
      };
      node = node->children;
    }
    // 判断是否为一个单词
    return node->word == Color::RED ? node : nullptr;
  }
  void keyCheck(std::string str) {
    if (str.empty() || str.size() == 0)
      throw std::string("字符串参数传递错误！！");
  }

 public:
  int Triesize() { return size; };
  bool empty() { return size == 0; };
  void clear() {
    size = 0;
    root = nullptr;
    delete root;
  };
  //   查看是否包含某个字符串
  bool contains(std::string str) {
    Node* node = findnode(str);
    if (node == nullptr) return false;
	return false;
  };
  std::string add(std::string str)
  {
	keyCheck(str);
	return "";
  };
  std::string remove(std::string str);
  //   查看是否有字符串以这个前缀开头
  bool starsWith(std::string prefix);
};
#endif  // __TRIE_H