#include <iostream>
using namespace std;

int main() {
  char symbol;
  cout << "Please enter a character: ";
  cin >> symbol;

  if (symbol >= 'a' && symbol <= 'z') {
    cout << "You entered a lowercase character" << endl;
		if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u') {
			cout << "you entered a vowel" << endl;
		} else {
			cout << "you entered a consonant" << endl;
		}
  } else if (symbol >= 'A' && symbol <= 'Z') {
		if (symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U') {
			cout << "you entered a vowel" << endl;
		} else {
			cout << "you entered a consonant" << endl;
		}
    cout << "You entered an uppercase character" << endl;
  } else if (symbol >= '0' && symbol <= '9' && symbol % 2 == 0) {
      cout << "You entered an even digit" << endl;
    } else if (symbol >= '0' && symbol <= '9') {
      cout << "You entered an odd digit" << endl;
		} else {
    cout << "You entered a special character" << endl;
  }

  return 0;
}
