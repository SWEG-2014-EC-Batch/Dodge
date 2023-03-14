#include <iostream>
using namespace std;

void half_pyramid() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void inverted_half_pyramid() {
  for (int i = 0; i < 5; i++) {
    for (int j = 5 - i; j > 0; j--) {
      cout << "* ";
    }
    cout << endl;
  }
}

void right_angled_triangle() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j < 5 - i - 1) {
        cout << " ";
      } else {
        cout << "*";
      }
    }
    cout << endl;
  }
}

void inverted_right_triangle() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j < 5 - i) {
        cout << "* ";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

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
}
