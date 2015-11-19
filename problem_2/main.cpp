#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------

string getMissingLetters(string &sentence);

//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	cout << "Problem #2" << endl;

	string sentence;

	// The user provided the strings in the command line
	if (argc >= 2) {
		sentence = argv[1];
	}
	// The user didn't provide the strings in the command line
	else {
		cout << "Enter sentence: ";
		cin >> sentence;
	}

	string missing_letters = getMissingLetters(sentence);

	cout << "There are " << missing_letters.size()
	     << " missing letters: " << missing_letters << endl;

	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------

/**
 * The basic idea of this function is to treat both the sentence and the
 * alphabet as Sets. The set difference between the alphabet and the sentence
 * gives us the elements (letters) that are missing in the sentence.
 */
string getMissingLetters(string &sentence)
{
	// Sorted set, without duplicate letters and with all lower case letters
	static const string english_alphabet("abcdefghijklmnopqrstuvwxyz");

	// We might have at most english_alphabet's length of missing letters
	string missing_letters = english_alphabet;

	// Convert sentence to lower case
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

	// Sort the sentence
	sort(sentence.begin(), sentence.end());

	// The missing letters are those that are present in english_alphabet,
	// but not in sentence
	string::iterator it = set_difference(
			english_alphabet.begin(), english_alphabet.end(),
			sentence.begin(), sentence.end(),
			missing_letters.begin());

	missing_letters.resize(it - missing_letters.begin());

	// Convert sentence to upper case
	transform(missing_letters.begin(), missing_letters.end(), missing_letters.begin(), ::toupper);

	return missing_letters;
}
