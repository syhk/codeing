#include "iostream"
#include "vector"
using namespace std;

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
                 const char* str, int& pathLength, bool* visited);
bool hasPath(char* matrix, int rows, int cols, char* str) {
  if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) return false;

  bool* visited = new bool[rows * cols];
  memset(visited, 0, rows * cols);

  int pathLength = 0;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
        return true;
      }
    }
  }
  delete[] visited;
  return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
                 const char* str, int& pathLength, bool* visited) {
  if (str[pathLength] == '\0') return true;

  bool hasPath = false;

  if (row >= 0 && row < rows && col >= 0 && col < cols &&
      matrix[row * cols + col] == str[pathLength] &&
      !visited[row * cols + col]) {
    ++pathLength;
    visited[row * cols + col] = true;
    hasPath =
        hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength,
                    visited) ||
        hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength,
                    visited) ||
        hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength,
                    visited) ||
        hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
    if (!hasPath) {
      --pathLength;
      visited[row * cols + col] = false;
    }
  }
  return hasPath;
}

class Solution {
 public:
  bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i,
             int j, string& s, int k) {
    if (board[i][j] != s[k]) {
      return false;
    } else if (k == s.length() - 1) {
      return true;
    }
    visited[i][j] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool result = false;
    for (const auto& dir : directions) {
      int newi = i + dir.first, newj = j + dir.second;
      if (newi >= 0 && newi < board.size() && newj >= 0 &&
          newj < board[0].size()) {
        if (!visited[newi][newj]) {
          bool flag = check(board, visited, newi, newj, s, k + 1);
          if (flag) {
            result = true;
            break;
          }
        }
      }
    }
    visited[i][j] = false;
    return result;
  }
  bool exist(vector<vector<char>>& board, string word) {
    int h = board.size(), w = board[0].size();
    vector<vector<int>> visited(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        bool flag = check(board, visited, i, j, word, 0);
        if (flag) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {}