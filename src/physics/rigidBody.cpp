#include <physics.hpp>

RigidBody::RigidBody(double cx, double cprevx, double ca, double cdx, unsigned int cmiliseconds,
	unsigned int cmiliseconds_hit, double ch, double camp, bool cbounce,
	unsigned int cBounceCount, double cxOffset, bool cxDirection, double cyOffset,
	bool cyDirection)
{
	this->x = (double*)malloc(sizeof(double));
	*this->x = cx;
	this->prevx = (double*)malloc(sizeof(double));
	*this->prevx = cx;
	this->a = (double*)malloc(sizeof(double));
	*this->a = ca;
	this->dx = (double*)malloc(sizeof(double));
	*this->dx = cdx;
	this->miliseconds = (unsigned int*)malloc(sizeof(unsigned int));
	*this->miliseconds = cmiliseconds;
	this->miliseconds_hit = (unsigned int*)malloc(sizeof(unsigned int));
	this->h = (double*)malloc(sizeof(double));
	*this->h = ch;
	this->bounce = (bool*)malloc(sizeof(bool));
	*this->bounce = cbounce;
	this->amp = (double*)malloc(sizeof(double));
	this->bounceCount = (unsigned int*)malloc(sizeof(unsigned int));
	*this->bounceCount = cBounceCount;
	this->xOffset = (double*)malloc(sizeof(double));
	*this->xOffset = cxOffset;
	this->xDirection = (bool*)malloc(sizeof(bool));
	*this->xDirection = cxDirection;
	this->yOffset = (double*)malloc(sizeof(double));
	*this->yOffset = cyOffset;
	this->yDirection = (bool*)malloc(sizeof(bool));
	*this->yDirection = cyDirection;
}
