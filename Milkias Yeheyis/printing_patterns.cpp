#include <iostream>
using namespace std;

void half_pyramid() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << "* ";
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
        cout << "  ";
      } else {
        cout << "* ";
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

void square() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 7; j++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void blank_rectangle() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (i == 0 || i == 6) {
        cout << "* ";
      } else if (j == 0 || j == 6) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void hollow_inverted_half_pyramid() {
  int number, i, j, h = 0;
  number = 6;

  for (i = 0; i < number; i++)
    cout << "* ";

  for (i = number; i >= 1; --i) {
    for (j = 0; j < number - i; ++j) {
      while (h != (2 * i - 1)) {
        if (h == 0 || h == 2 * i - 2)
          cout << "*";
        else
          cout << " ";
        h++;
      }
    }
    h = 0;
    cout << endl;
  }
}

void full_pyramid() {
  int rows = 6;
  int space;

  for (int i = 1, k = 0; i <= rows; ++i, k = 0) {
    for (space = 1; space <= rows - i; ++space) {
      cout << "  ";
    }

    while (k != 2 * i - 1) {
      cout << "* ";
      ++k;
    }
    cout << endl;
  }
}

void inverted_pyramid() {
  int rows = 6;

  for (int i = rows; i >= 1; --i) {
    for (int space = 0; space < rows - i; ++space)
      cout << "  ";

    for (int j = i; j <= 2 * i - 1; ++j)
      cout << "* ";

    for (int j = 0; j < i - 1; ++j)
      cout << "* ";

    cout << endl;
  }
}

void basic_with_numbers() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << j + 1 << " ";
    }
    cout << endl;
  }
}

void basic_with_letters() {
  for (int i = 0; i < 5; i++) {
    for (char j = 97; j < 102; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void basic_with_capital_letters() {
  char cur = 'A';
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      cout << cur++ << " ";
    }
    cout << endl;
  }
}

void right_angled_triangle_letters() {
  int i, j, rows = 5;

  char c = 'A';

  for (i = 1; i <= rows; i++) {
    c = 'A';

    for (j = 1; j <= i; j++) {
      cout << c << " ";

      c += 1;
    }

    cout << endl;
  }
}

void hollow_full_pyramid() {
  int n, i, j;
  n = 6;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= (n - i); j++) {
      cout << " ";
    }
    if (i == 1 || i == n) {
      for (j = 1; j <= i; j++) {
        cout << "* ";
      }
    } else {
      cout << "*";
      for (j = 1; j <= 2 * i - 3; j++) {
        cout << " ";
      }
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
	half_pyramid();
	cout << endl;
	inverted_half_pyramid();
	cout << endl;
	right_angled_triangle();
	cout << endl;
	inverted_right_triangle();
	cout << endl;
	square();
	cout << endl;
	blank_rectangle();
	cout << endl;
	hollow_inverted_half_pyramid();
	cout << endl;
	full_pyramid();
	cout << endl;
	inverted_pyramid();
	cout << endl;
	basic_with_numbers();
	cout << endl;
	basic_with_capital_letters();
	cout << endl;
	right_angled_triangle_letters();
	cout << endl;
	hollow_full_pyramid();
	cout << endl;
  right_angled_triangle_letters();

  return 0;
}
