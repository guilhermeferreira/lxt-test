#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

bool isRotation(
	const string &s1,
	const string &s2);

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

bool isRotation(
	const string &s1,
	const string &s2)
{
	// If we imagine that s1 and s2 are two sets of characters, this problem
	// can be reduced to know if both sets have the same elements. We might
	// perform a lexicographical ordering on both sets and check if the
	// resulting sets are equal.
	string sorted_s1 = s1;
	string sorted_s2 = s2;

	sort(sorted_s1.begin(), sorted_s1.end());
	sort(sorted_s2.begin(), sorted_s2.end());

	cout << "sorted s1 = '" << sorted_s1 << "'" << endl;
	cout << "sorted s2 = '" << sorted_s2 << "'" << endl;

	return (sorted_s1.compare(sorted_s2) == 0);
}

