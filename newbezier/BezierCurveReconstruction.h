#pragma once
#include <iostream>
using namespace std;
#ifndef GG_H

#define GG_H 1
struct Point2Struct
{
	double x, y;
   // Point2Struct operator = (const Point2Struct&T, float &);
	friend void input() ;
	void show() {
		cout << "\nx: " << x << "\t y: " << y;
	}
};

typedef Point2Struct Point2;

typedef Point2Struct Vector2;
struct IntPoint2Struct {
	int x, y;
};
typedef IntPoint2Struct IntPoint2;
struct Matrix3Struct {
	double element[3][3];
};
struct Box2dStruct {
	Point2Struct min, max;
};
/************************/
/* one-argument macros */
/***********************/

/* absolute value of a */
#define ABS(a)		(((a)<0) ? -(a) : (a))

/* round a to nearest int */
#define ROUND(a)	((a)>0 ? (int)((a)+0.5) : -(int)(0.5-(a)))

/* take sign of a, either -1, 0, or 1 */
#define ZSGN(a)		(((a)<0) ? -1 : (a)>0 ? 1 : 0)	

/* take binary sign of a, either -1, or 1 if >= 0 */
#define SGN(a)		(((a)<0) ? -1 : 1)

/* shout if something that should be true isn't */
#define ASSERT(x) \
if (!(x)) fprintf(stderr," Assert failed: x\n");

/* square a */
#define SQR(a)		((a)*(a))	


/***********************/
/* two-argument macros */
/***********************/

/* find minimum of a and b */
#define MIN(a,b)	(((a)<(b))?(a):(b))	

/* find maximum of a and b */
#define MAX(a,b)	(((a)>(b))?(a):(b))	

/* swap a and b (see Gem by Wyvill) */
#define SWAP(a,b)	{ a^=b; b^=a; a^=b; }

/* linear interpolation from l (when a=0) to h (when a=1)*/
/* (equal to (a*h)+((1-a)*l) */
#define LERP(a,l,h)	((l)+(((h)-(l))*(a)))

/* clamp the input to the specified range */
#define CLAMP(v,l,h)	((v)<(l) ? (l) : (v) > (h) ? (h) : v)


/****************************/
/* memory allocation macros */
/****************************/

/* create a new instance of a structure (see Gem by Hultquist) */
#define NEWSTRUCT(x)	(struct x *)(malloc((unsigned)sizeof(struct x)))

/* create a new instance of a type */
#define NEWTYPE(x)	(x *)(malloc((unsigned)sizeof(x)))


/********************/
/* useful constants */
/********************/

#define PI		3.141592	/* the venerable pi */
#define PITIMES2	6.283185	/* 2 * pi */
#define PIOVER2		1.570796	/* pi / 2 */
#define E		2.718282	/* the venerable e */
#define SQRT2		1.414214	/* sqrt(2) */
#define SQRT3		1.732051	/* sqrt(3) */
#define GOLDEN		1.618034	/* the golden ratio */
#define DTOR		0.017453	/* convert degrees to radians */
#define RTOD		57.29578	/* convert radians to degrees */


/************/
/* booleans */
/************/

#define TRUE		1
#define FALSE		0
#define ON		1
#define OFF 		0
typedef int boolean;			/* boolean data type */
typedef boolean flag;			/* flag data type */

extern double V2SquaredLength(), V2Length();
extern double V2Dot(), V2DistanceBetween2Points();
extern Vector2* V2Negate(), * V2Normalize(), * V2Scale(), * V2Add(), * V2Sub();
extern Vector2* V2Lerp(), * V2Combine(), * V2Mul(), * V2MakePerpendicular();
extern Vector2* V2New(), * V2Duplicate();
extern Vector2* V2MulPointByMatrix();// point2
extern Matrix3Struct* V2MatMul();

//extern double V3SquaredLength(), V3Length();
//extern double V3Dot(), V3DistanceBetween2Points();
//extern Vector3* V3Normalize(), * V3Scale(), * V3Add(), * V3Sub();
//extern Vector3* V3Lerp(), * V3Combine(), * V3Mul(), * V3Cross();
//extern Vector3* V3New(), * V3Duplicate();
//extern Point3* V3MulPointByMatrix();
//extern Matrix4* V3MatMul();
extern double RegulaFalsi(), NewtonRaphson(), findroot();

#endif