#include "iostream"
#include "map"
#include "queue"
#include "stack"
#include "vector"

using namespace std;

/*
给定一个有 n 个节点的有向无环图，用二维数组 graph 表示，
请找到所有从 0 到 n-1 的路径并输出（不要求按顺序）。
图结构为邻接表表示
*/
class Solution {
 public:
  vector<vector<int>> ans;  // 最终结果
  vector<int> stk;          // 当前遍历的路径
  void dfs(vector<vector<int>>& graph, int x, int n) {
    if (x == n) {
      ans.push_back(stk);
      return;
    }
    for (auto& y : graph[x]) {
      stk.push_back(y);
      dfs(graph, y, n);
      stk.pop_back();
    }
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    stk.push_back(0);  // 存放根结点
    dfs(graph, 0, graph.size() - 1);
    return ans;
  }
};

int main() {}