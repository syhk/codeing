#include <string>

#include "iostream"
#include "string"

using namespace std;

template <class T> 
int hashCode(T value);
int main(void) {
  string s = "hello world!";
  long long hashCode = 0;
  float f = 1.2f;
  if (typeid(f) == typeid(float)) {
    hashCode = f;
  }
  cout << hashCode << endl;
  for (int i = 0; i < s.length(); i++) {
    hashCode = (hashCode << 5) - hashCode + s[i];  // java 官方计算方法
  }
  cout << hashCode << endl;
  return 0;
}
template <class T> 
int hashCode(T value)
{
  if(typeid(T) == typeid(float))
  {
    // processing 
  }
  else if(typeid(T) == typeid(int))
  {
   return static_cast<int>(value); 
  }
  else if(typeid(T) == typeid(long))
  {
    // processing 
  }
  else if(typeid(T) == typeid(string))
  {
    // processing 
  }else {//自定义对象

  }

}

