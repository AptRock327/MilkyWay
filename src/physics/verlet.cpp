#include <physics.hpp>

double nextfx(double a, double fx, double prevfx, double dx)
{
	return 2 * fx + a * dx * dx - prevfx;
}

void recalculate(RigidBody* body)
{
	if(*body->bounceCount > 100) return;

	*body->miliseconds+=1;

	if(*body->xOffset > 4) *body->xDirection = false;
	if(*body->xOffset < -4) *body->xDirection = true;
	if(*body->yOffset > 2) *body->yDirection = false;
	if(*body->yOffset < -2) *body->yDirection = true;

	if((*body->bounceCount > 10) && (*body->miliseconds % 100 == 0)) *body->bounceCount+=2;

	if(*body->miliseconds % (*body->bounceCount+1 * 4) == 0) *body->xOffset+=(*body->xDirection ? 0.05 : -0.05);
	if(*body->miliseconds % (*body->bounceCount+1 * 4) == 0) *body->yOffset+=(*body->yDirection ? 0.05 : -0.05);

	double omega, tmp;
	if(*body->x >= 0)
	{
		tmp = *body->x;
		if(!*body->bounce)
		{
			*body->x = nextfx(*body->a, *body->x, *body->prevx, *body->dx);
		}
		else
		{
			omega = sqrt(0.1f);
			double acc = *body->a + *body->amp * cos(omega * (double)(*body->miliseconds - *body->miliseconds_hit)/1000);
			*body->x = nextfx(acc, *body->x, *body->prevx, *body->dx);
			if(*body->x < tmp)
			{
				*body->bounce = false;
				*body->h = tmp-(tmp/2);
			}
		}
		*body->prevx = tmp;
	}
	else
	{
		if(!*body->bounce)
		{
			*body->miliseconds_hit = *body->miliseconds;
			*body->x = -0.1;
			*body->prevx = -0.106+(0.0005*(double)(*body->bounceCount));
			*body->bounceCount += 1;
		}
		*body->bounce = true;
		*body->amp = sqrt( (2 * 9.81 * *body->h)/6.0f );
		double tmp = *body->x;
		double omega = sqrt(6.0f);
		double acc = *body->a + *body->amp * cos(omega * (double)(*body->miliseconds - *body->miliseconds_hit)/1000);
		*body->x = nextfx(acc, *body->x, *body->prevx, *body->dx);
		if(*body->x < tmp) *body->x = tmp;
		else *body->prevx = tmp;
	}
}
