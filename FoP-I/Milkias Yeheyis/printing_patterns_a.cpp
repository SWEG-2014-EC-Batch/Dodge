#include <iostream>
using namespace std;

int main() {
  int width, height;
  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;

  int num = 10;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (num != 10 && num % 10 == 0) {
        cout << "\n" << num++ << " ";
      } else {
        cout << num++ << " ";
      }
    }
  }
  cout << endl;
  return 0;
}
