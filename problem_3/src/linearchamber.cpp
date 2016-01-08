#include "linearchamber.h"

#include <cassert>

#include <algorithm>

using std::string;
using std::vector;

//-----------------------------------------------------------------------------

LinearChamber::LinearChamber(
	const string &init,
	int speed
) :
	particles_(),
	init_chamber_(init),
	curr_chamber_(init),
	speed_(speed)
{
	assert(init_chamber_.length() == curr_chamber_.length());
}

//-----------------------------------------------------------------------------

LinearChamber::~LinearChamber()
{
}

//-----------------------------------------------------------------------------

void LinearChamber::createParticles()
{
	int position = 0;

	// For each 'R' and 'L', create a Particle object
	// Particle has speed (int) and direction (string)
	for (string::iterator it = init_chamber_.begin(); it != init_chamber_.end(); ++it) {
		char direction = *it;

		if (isParticle(direction)) {
			Particle p = createParticle(direction, position);
			particles_.push_back(p);
		}

		position++;
	}
}

//-----------------------------------------------------------------------------

Particle LinearChamber::createParticle(
	char direction,
	int position)
{
	assert((direction == 'L') || (direction == 'R'));
	assert((0 <= position) && (position < static_cast<int>(init_chamber_.length())));

	Direction dir = (direction == 'L') ? DirectionLeft : DirectionRight;
	Particle particle(dir, position, speed_);

	return particle;
}

//-----------------------------------------------------------------------------

bool LinearChamber::isParticle(char direction)
{
	return ((direction == 'L') || (direction == 'R'));
}

//-----------------------------------------------------------------------------

void LinearChamber::moveParticles()
{
	for (vector<Particle>::iterator it = particles_.begin(); it != particles_.end(); ++it) {
		Particle &p = *it;
		p.move();
	}
}

//-----------------------------------------------------------------------------

string LinearChamber::printParticles()
{
	assert(init_chamber_.length() == curr_chamber_.length());

	// The idea is to fill the chamber with '.' and print a 'X' only on those
	// positions that there are particles

	fill(curr_chamber_.begin(), curr_chamber_.end(), '.');

	const int chamber_size = static_cast<int>(curr_chamber_.length());

	for (vector<Particle>::iterator it = particles_.begin(); it != particles_.end(); ++it) {
		Particle &p = *it;
		int pos = p.getPosition();

		// Avoid writing a 'X' out of string bounds (i.e. buffer overflow)
		if ((0 <= pos) && (pos < chamber_size)) {
			unsigned int upos = static_cast<unsigned int>(pos);
			curr_chamber_[upos] = 'X';
		}
	}

	return curr_chamber_;
}

//-----------------------------------------------------------------------------

bool LinearChamber::isEmpty()
{
	assert(init_chamber_.length() == curr_chamber_.length());

	const int chamber_size = static_cast<int>(curr_chamber_.length());

	return (count(curr_chamber_.begin(), curr_chamber_.end(), '.') == chamber_size);
}
