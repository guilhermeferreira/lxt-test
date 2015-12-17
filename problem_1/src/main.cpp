#include <cstdlib>

#include <iostream>
#include <string>

#include "rotation.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using luxoft::isRotation;

int main(int argc, char *argv[])
{
	cout << "Problem #1" << endl;

	string s1;
	string s2;

	// The user provided the strings in the command line
	if (argc >= 3) {
		s1 = argv[1];
		s2 = argv[2];
	}
	// The user didn't provide the strings in the command line
	else {
		cout << "Enter string #1: ";
		cin >> s1;

		cout << "Enter string #2: ";
		cin >> s2;
	}

	cout << "s1 = '" << s1 << "'" << endl;
	cout << "s2 = '" << s2 << "'" << endl;

	if (isRotation(s1, s2)) {
		cout << "'" << s2 << "' is a rotation of string '" << s1 << "'\n" << endl;
	} else {
		cout << "'" << s2 << "' is NOT a rotation of string '" << s1 << "'\n" << endl;
	}

	return EXIT_SUCCESS;
}
