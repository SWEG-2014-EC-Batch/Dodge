#include <cstdlib>
#include <iostream>
using namespace std;

void input(int *var, int maxVal, string varName, int trials=0) {
	cout << "Enter " << varName << " (" << maxVal << "%): ";
	cin >> *var;
	if (*var > maxVal || *var < 0) {
		if (trials >= 5) {
			cout << "You have entered an invalid value 5 times, I'm done with you" << endl;
			exit(-1);
		}
		cout << "You entered an invalid value for " << varName << endl;
		input(var, maxVal, varName, trials + 1);
	}
}

int main() {
	int test, quiz, project, assignment, finalExam;

	input(&test, 15, "test");
	input(&quiz, 5, "quiz");
	input(&project, 20, "project");
	input(&assignment, 10, "assignment");
	input(&finalExam, 50, "final exam");

	int courseMark = test + quiz + project + assignment + finalExam;

  if (courseMark >= 90) {
    cout << "A+" << endl;
  } else if (courseMark >= 80) {
    cout << "A" << endl;
  } else if (courseMark >= 75) {
    cout << "B+" << endl;
  } else if (courseMark >= 60) {
    cout << "B" << endl;
  } else if (courseMark >= 55) {
    cout << "C+" << endl;
  } else if (courseMark >= 45) {
    cout << "C" << endl;
  } else if (courseMark >= 30) {
    cout << "D" << endl;
  } else {
    cout << "F" << endl;
  }

  return 0;
}
