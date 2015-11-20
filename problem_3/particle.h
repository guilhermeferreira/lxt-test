#ifndef PARTICLE_H
#define PARTICLE_H

//-----------------------------------------------------------------------------
// Direction
//-----------------------------------------------------------------------------

// In portuguese this would be "sense", not direction.
// But I'm not sure about vector terminology in english
enum Direction {
	DirectionLeft = -1,
	DirectionRight = 1
};

//-----------------------------------------------------------------------------
// Particle
//-----------------------------------------------------------------------------

class Particle {
public:
	Particle(
		const Direction direction,
		const int position,
		const int speed);

	virtual ~Particle();

	void move();

	int getPosition();

private:
	Direction direction_;
	int position_;
	int speed_;

};

#endif /* PARTICLE_H */
