#ifndef LINEARCHAMBER_H
#define LINEARCHAMBER_H

#include "chamber.h"

#include <vector>
#include <string>

#include "particle.h"

//-----------------------------------------------------------------------------
// LinearChamber
//-----------------------------------------------------------------------------

class LinearChamber : public Chamber {
public:
	LinearChamber(
		const std::string &init,
		int speed);

	virtual ~LinearChamber();

	void createParticles();

	void moveParticles();

	std::string printParticles();

	bool isEmpty();

protected:
	Particle createParticle(
		char direction,
		int position);

	bool isParticle(char direction);

private:
	std::vector<Particle> particles_;
	std::string init_chamber_;
	std::string curr_chamber_;
	int speed_;

};

#endif /* LINEARCHAMBER_H */
