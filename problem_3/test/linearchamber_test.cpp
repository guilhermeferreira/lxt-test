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
#include "linearchamber_test.h"

#include "linearchamber.h"


//-----------------------------------------------------------------------------
// LinearChamberTest class
//-----------------------------------------------------------------------------

LinearChamberTest::LinearChamberTest()
{
	TEST_ADD(LinearChamberTest::createParticles_Test);
	TEST_ADD(LinearChamberTest::moveParticles_Test);
	TEST_ADD(LinearChamberTest::printParticles_Test);
	TEST_ADD(LinearChamberTest::isEmpty_Test);
	TEST_ADD(LinearChamberTest::createParticle_Test);
	TEST_ADD(LinearChamberTest::isParticle_Test);
}

//-----------------------------------------------------------------------------

void LinearChamberTest::createParticles_Test()
{
	LinearChamber c = LinearChamber("RR..", 1);
	c.createParticles();
}

//-----------------------------------------------------------------------------

void LinearChamberTest::createParticle_Test()
{
	LinearChamber c = LinearChamber("R.L", 1);

	Particle pl1 = c.createParticle('L', 2);
	TEST_ASSERT(pl1.getPosition() == 2);
	pl1.move();
	TEST_ASSERT(pl1.getPosition() == 1);
	pl1.move();
	TEST_ASSERT(pl1.getPosition() == 0);

	Particle pr0 = c.createParticle('R', 0);
	TEST_ASSERT(pr0.getPosition() == 0);
	pr0.move();
	TEST_ASSERT(pr0.getPosition() == 1);
	pr0.move();
	TEST_ASSERT(pr0.getPosition() == 2);
}

//-----------------------------------------------------------------------------

void LinearChamberTest::moveParticles_Test()
{
	LinearChamber c1 = LinearChamber("R..L", 1);
	c1.createParticles();
	TEST_ASSERT(c1.printParticles() == "X..X");
	c1.moveParticles();
	c1.moveParticles();
	c1.moveParticles();
	c1.moveParticles();
	TEST_ASSERT(c1.printParticles() == "....");

	LinearChamber c2 = LinearChamber("..L..R..", 2);
	c2.createParticles();
	TEST_ASSERT(c2.printParticles() == "..X..X..");
	c2.moveParticles();
	c2.moveParticles();
	TEST_ASSERT(c2.printParticles() == "........");

	LinearChamber c3 = LinearChamber("R......", 3);
	c3.createParticles();
	TEST_ASSERT(c3.printParticles() == "X......");
	c3.moveParticles();
	c3.moveParticles();
	c3.moveParticles();
	TEST_ASSERT(c3.printParticles() == ".......");

	LinearChamber c4 = LinearChamber("........L", 4);
	c4.createParticles();
	TEST_ASSERT(c4.printParticles() == "........X");
	c4.moveParticles();
	c4.moveParticles();
	c4.moveParticles();
	TEST_ASSERT(c4.printParticles() == ".........");
}

//-----------------------------------------------------------------------------

void LinearChamberTest::printParticles_Test()
{
	LinearChamber c1 = LinearChamber("R..L", 1);
	c1.createParticles();
	TEST_ASSERT(c1.printParticles() == "X..X");
	c1.moveParticles();
	TEST_ASSERT(c1.printParticles() == ".XX.");
	c1.moveParticles();
	TEST_ASSERT(c1.printParticles() == ".XX.");
	c1.moveParticles();
	TEST_ASSERT(c1.printParticles() == "X..X");
	c1.moveParticles();
	TEST_ASSERT(c1.printParticles() == "....");
	c1.moveParticles();
	TEST_ASSERT(c1.printParticles() == "....");

	LinearChamber c2 = LinearChamber("..L..R..", 2);
	c2.createParticles();
	TEST_ASSERT(c2.printParticles() == "..X..X..");
	c2.moveParticles();
	TEST_ASSERT(c2.printParticles() == "X......X");
	c2.moveParticles();
	TEST_ASSERT(c2.printParticles() == "........");
	c2.moveParticles();
	TEST_ASSERT(c2.printParticles() == "........");

	LinearChamber c3 = LinearChamber("R......", 3);
	c3.createParticles();
	TEST_ASSERT(c3.printParticles() == "X......");
	c3.moveParticles();
	TEST_ASSERT(c3.printParticles() == "...X...");
	c3.moveParticles();
	TEST_ASSERT(c3.printParticles() == "......X");
	c3.moveParticles();
	TEST_ASSERT(c3.printParticles() == ".......");
	c3.moveParticles();
	TEST_ASSERT(c3.printParticles() == ".......");

	LinearChamber c4 = LinearChamber("........L", 4);
	c4.createParticles();
	TEST_ASSERT(c4.printParticles() == "........X");
	c4.moveParticles();
	TEST_ASSERT(c4.printParticles() == "....X....");
	c4.moveParticles();
	TEST_ASSERT(c4.printParticles() == "X........");
	c4.moveParticles();
	TEST_ASSERT(c4.printParticles() == ".........");
	c4.moveParticles();
	TEST_ASSERT(c4.printParticles() == ".........");
}

//-----------------------------------------------------------------------------

void LinearChamberTest::isEmpty_Test()
{
	LinearChamber c1r = LinearChamber("R", 1);
	c1r.createParticles();
	c1r.printParticles();
	TEST_ASSERT(c1r.isEmpty() == false);
	c1r.moveParticles();
	c1r.printParticles();
	TEST_ASSERT(c1r.isEmpty() == true);

	LinearChamber c1l = LinearChamber("L", 1);
	c1l.createParticles();
	c1l.printParticles();
	TEST_ASSERT(c1l.isEmpty() == false);
	c1l.moveParticles();
	c1l.printParticles();
	TEST_ASSERT(c1l.isEmpty() == true);
}

//-----------------------------------------------------------------------------

void LinearChamberTest::isParticle_Test()
{
	LinearChamber c = LinearChamber("R", 1);
	TEST_ASSERT(c.isParticle('L') == true);
	TEST_ASSERT(c.isParticle('R') == true);

	TEST_ASSERT(c.isParticle('A') == false);
	TEST_ASSERT(c.isParticle('B') == false);
	TEST_ASSERT(c.isParticle('C') == false);
	TEST_ASSERT(c.isParticle('D') == false);
	TEST_ASSERT(c.isParticle('E') == false);
	TEST_ASSERT(c.isParticle('F') == false);
	TEST_ASSERT(c.isParticle('G') == false);
	TEST_ASSERT(c.isParticle('H') == false);
	TEST_ASSERT(c.isParticle('I') == false);
	TEST_ASSERT(c.isParticle('J') == false);
	TEST_ASSERT(c.isParticle('M') == false);
	TEST_ASSERT(c.isParticle('N') == false);
	TEST_ASSERT(c.isParticle('O') == false);
	TEST_ASSERT(c.isParticle('P') == false);
	TEST_ASSERT(c.isParticle('Q') == false);
	TEST_ASSERT(c.isParticle('S') == false);
	TEST_ASSERT(c.isParticle('T') == false);
	TEST_ASSERT(c.isParticle('U') == false);
	TEST_ASSERT(c.isParticle('V') == false);
	TEST_ASSERT(c.isParticle('X') == false);
	TEST_ASSERT(c.isParticle('Y') == false);
	TEST_ASSERT(c.isParticle('Z') == false);
}
