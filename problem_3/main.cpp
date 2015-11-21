#include <cassert>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "linearchamber.h"

using namespace std;

//-----------------------------------------------------------------------------

bool isValid(
	const string &init,
	const int speed);

vector<string> animate(
	const string &init,
	const int speed);

void show(const string &element);

//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	cout << "Problem #3" << endl;

	// String containing at each position an 'L' for a leftward moving
	// particle, an 'R' for a rightward moving particle, or a '.' for
	// an empty location
	string init;
	int speed;

	// The user provided the strings in the command line
	if (argc >= 3) {
		init = argv[1];

#if __cplusplus >= 201103L // Macro value defined at section 16.8. Predefined macro names [ISO/IEC 14882:2011]
		// New C++11 feature described in section 21.5. Numeric conversions [ISO/IEC 14882:2011]
		speed = stoi(argv[2]);
#else
		// Use C++98 style described in section 27.7.2. Template class basic_istringstream [ISO/IEC 14882:1998]
		istringstream stream(argv[2]);
		stream >> speed;
#endif

	}
	// The user didn't provide the strings in the command line
	else {
		cout << "Enter a string composed of 'L', 'R' or '.': ";
		cin >> init;
		cout << "Enter speed: ";
		cin >> speed;
	}

	cout << "Init : '" << init << "'" << endl;
	cout << "Speed: " << speed << endl;

	if (!isValid(init, speed)) {
		cerr << "Error: invalid input" << endl;
		return EXIT_FAILURE;
	}

	vector<string> animation = animate(init, speed);

	for_each(animation.begin(), animation.end(), show);

	cout << endl;

	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------

/**
 * \brief Check if input is valid and within range
 *
 * \param init    contains all the positions in the chamber.
 * \param speed   The number of positions each particle moves in one time unit.
 *
 * \return true if the input are within range, or false otherwise.
 */
bool isValid(
	const string &init,
	const int speed)
{
	const int chamber_size = static_cast<int>(init.length());

	// character count must be in range [1, 50]
	if ((chamber_size < 1) || (50 < chamber_size)) {
		return false;
	}

	// each character must be in set {'.', 'L', 'R'}
	int dot_count = static_cast<int>(count(init.begin(), init.end(), '.'));
	int left_count = static_cast<int>(count(init.begin(), init.end(), 'L'));
	int right_count = static_cast<int>(count(init.begin(), init.end(), 'R'));
	int valid_chars = dot_count + left_count + right_count;
	if (valid_chars != chamber_size) {
		return false;
	}

	// speed must be between in range [1, 10]
	if ((speed < 1) || (10 < speed)) {
		return false;
	}

	return true;
}

//-----------------------------------------------------------------------------

/**
 * \brief Animation of the process
 *
 * At each unit of time, we want a string showing occupied locations with an
 * 'X' and unoccupied locations with a '.'.
 *
 * The first element of the return should show the occupied locations at the
 * initial instant (at time = 0) in the 'X','.' format. The last element in
 * the return should show the empty chamber at the first time that it becomes
 * empty.
 *
 * \param init    contains all the positions in the chamber.
 * \param speed   The number of positions each particle moves in one time unit.
 *
 * \return a std::vector of std::string in which each successive element shows
 *         the occupied locations at the next time unit.
 */
vector<string> animate(
	const string &init,
	const int speed)
{
	// init contains between 1 and 50 characters inclusive
	assert((1 <= init.length()) && (init.length() <= 50));
	// speed will be between 1 and 10 inclusive
	assert((1 <= speed) && (speed <= 10));

	vector<string> animation;

#if __cplusplus >= 201103L // Macro value defined in section 16.8. Predefined macro names [ISO/IEC 14882:2011]
	// Use C++11 smart pointer described in section 20.7.1. Class template unique_ptr [ISO/IEC 14882:2011]
	unique_ptr<Chamber> chamber(new LinearChamber(init, speed));
#else
	// Use C++98 smart pointer described in section 20.4.5. Template class auto_ptr [ISO/IEC 14882:1998]
	auto_ptr<Chamber> chamber(new LinearChamber(init, speed));
#endif

	chamber->createParticles();

	do {
		animation.push_back(chamber->printParticles());

		chamber->moveParticles();
	} while (!chamber->isEmpty());

	return animation;
}

//-----------------------------------------------------------------------------

/**
 * \brief Show one element of animation vector
 *
 * \param element   shows the occupied locations at the next time unit.
 */
void show(const string &element)
{
	cout << "  " << element << endl;
}
