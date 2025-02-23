#ifndef __PHYSICS_HPP
#define __PHYSICS_HPP

#include <cstdlib>
#include <math.h>

/** Struct representing a rigid body and its physics parameters */
struct RigidBody
{
	double* x;
	double* prevx;
	double* a;
	double* dx;
	unsigned int* miliseconds;
	unsigned int* miliseconds_hit;
	double* h;
	double* amp;
	bool* bounce;
	unsigned int* bounceCount;
	double* xOffset;
	bool* xDirection;
	double* yOffset;
	bool* yDirection;

	RigidBody(double cx, double cprevx, double ca, double cdx, unsigned int cmiliseconds,
		unsigned int cmiliseconds_hit, double ch, double camp, bool cbounce,
		unsigned int cBounceCount, double cxOffset, bool cxDirection, double cyOffset,
		bool cyDirection);
};

/** Calculates the next position using Verlet integration
 * @a - acceleration
 * @fx - current position
 * @prevfx - previous position
 * @dx - time step
 * Returns: next position
 */
double nextfx(double a, double fx, double prevfx, double dx);

/** Recalculates all of the values in the next time step dx
 * @body - pointer to rigid body to move according to its physics parameters
 * Returns: none
 */
void recalculate(RigidBody* body);

#endif
