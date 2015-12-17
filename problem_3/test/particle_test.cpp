/**
 * Copyright(c) 2015 Guilherme M. Ferreira <guilherme.maciel.ferreira@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "particle_test.h"

#include "particle.h"



//-----------------------------------------------------------------------------
// ParticleTest class
//-----------------------------------------------------------------------------

ParticleTest::ParticleTest()
{
	TEST_ADD(ParticleTest::move_one_Test);
	TEST_ADD(ParticleTest::move_three_Test);
	TEST_ADD(ParticleTest::getPosition_Test);
}

//-----------------------------------------------------------------------------

void ParticleTest::move_one_Test()
{
	Particle p1(DirectionLeft, 10, 1);

	TEST_ASSERT(p1.getPosition() == 10);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 9);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 8);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 7);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 6);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 5);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 4);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 3);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 2);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 1);
	p1.move();
	TEST_ASSERT(p1.getPosition() == 0);
}

//-----------------------------------------------------------------------------

void ParticleTest::move_three_Test()
{
	Particle p3(DirectionLeft, 9, 3);

	TEST_ASSERT(p3.getPosition() == 9);
	p3.move();
	TEST_ASSERT(p3.getPosition() == 6);
	p3.move();
	TEST_ASSERT(p3.getPosition() == 3);
	p3.move();
	TEST_ASSERT(p3.getPosition() == 0);
}

//-----------------------------------------------------------------------------

void ParticleTest::getPosition_Test()
{
	Particle p1(DirectionLeft, 10, 1);
	TEST_ASSERT(p1.getPosition() == 10);

	Particle p2(DirectionLeft, 20, 2);
	TEST_ASSERT(p2.getPosition() == 20);

	Particle p3(DirectionLeft, 30, 3);
	TEST_ASSERT(p3.getPosition() == 30);

	Particle p4(DirectionLeft, 40, 4);
	TEST_ASSERT(p4.getPosition() == 40);

	Particle p5(DirectionLeft, 50, 5);
	TEST_ASSERT(p5.getPosition() == 50);

	Particle p6(DirectionLeft, 60, 6);
	TEST_ASSERT(p6.getPosition() == 60);
}
