#ifndef CHAMBER_H
#define CHAMBER_H

#include <string>

//-----------------------------------------------------------------------------
// Chamber
//-----------------------------------------------------------------------------

class Chamber {
public:
	Chamber();

	virtual ~Chamber();

	virtual void createParticles() = 0;

	virtual void moveParticles() = 0;

	virtual std::string printParticles() = 0;

	virtual bool isEmpty() = 0;

};

#endif /* CHAMBER_H */
