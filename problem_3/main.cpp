#include <cassert>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//-----------------------------------------------------------------------------

class Particle {
public:
	enum Direction {
		DirectionLeft,
		DirectionRight
	};

	Particle(Direction dir);
	virtual ~Particle();

private:
	Direction dir_;
};

Particle::Particle(Direction dir) : dir_(dir)
{
}

Particle::~Particle()
{

}

//-----------------------------------------------------------------------------

class Chamber {
public:

};

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
		speed = stoi(argv[2]); // New C++11 feature described in section 21.5. Numeric conversions [ISO/IEC 14882:2011]

#else // Use C++98 style described in section 27.7.2. Template class basic_istringstream [ISO/IEC 14882:1998]
		istringstream stream(argv[2]);
		stream >> speed;
#endif

	}
	// The user didn't provide the strings in the command line
	else {
		cout << "Enter init [string of 'L', 'R' or '.']: ";
		cin >> init;
		cout << "Enter speed: ";
		cin >> speed;
	}

	if (!isValid(init, speed)) {
		return EXIT_FAILURE;
	}

	vector<string> animation = animate(init, speed);

	for_each(animation.begin(), animation.end(), show);

	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------

/**
 * \brief Check if input is valid and within range
 *
 * \param init    contains all the positions in the chamber.
 * \param speed   The number of positions each particle moves in one time unit.
 *
 * \return true if the inputs are within range, or false otherwise.
 */
bool isValid(
	const string &init,
	const int speed)
{
	// init contains between 1 and 50 characters inclusive
	if ((init.length() < 1) || (50 < init.length())) {
		return false;
	}

	// each character in init will be '.' or 'L' or 'R'
	// TODO check if init contains other characters besides

	// speed will be between 1 and 10 inclusive
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

	/*
	 * For each 'R' and 'L', create a Particle object
	 * Particle has (int) speed and (string) direction
	 * Chamber prints dots '.' and set bounds and
	 */

	animation.push_back(init);

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
	cout << element << endl;
}
