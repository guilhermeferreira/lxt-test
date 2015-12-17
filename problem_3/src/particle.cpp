#include "particle.h"

#include <cassert>

//-----------------------------------------------------------------------------

Particle::Particle(
	const Direction direction,
	const int position,
	const int speed
) : direction_(direction),
    position_(position),
    speed_(speed)
{
	assert((1 <= speed) && (speed <= 10));
}

//-----------------------------------------------------------------------------

Particle::~Particle()
{
}

//-----------------------------------------------------------------------------

void Particle::move()
{
	// Leftwards moving particles receive a negative direction
	// Rightwards moving particles receive a positive direction
	position_ += (static_cast<int>(direction_) * speed_);
}

//-----------------------------------------------------------------------------

int Particle::getPosition()
{
	return position_;
}
