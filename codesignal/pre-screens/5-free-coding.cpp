#include <iostream>
#include <jsoncpp/json/json.h>
using namespace std;

int main() {
  int N = 10;
  int width = N * 2 - 1;
  for (int i = 0; i < N; ++i) {
    int start = width / 2 - i;
    int end = start + i * 2;
    for (int j = 0; j < width; ++j) {
      if (j >= start && j <= end) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}