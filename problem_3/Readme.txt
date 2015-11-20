---------------------------------------
Classes
---------------------------------------

The idea behind my solution is to delegate part of the movement responsability
to different classes. The LinearChamber knows all particles and can make them
move. The Particle knows its own position and direction, thus it can move only
itself. 

Particle: represents each particle

Chamber: abstract class for chambers

LinearChamber: a concreate class representing a linear chamber