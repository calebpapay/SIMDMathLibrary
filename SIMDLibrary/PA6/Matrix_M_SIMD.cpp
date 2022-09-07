//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

Matrix_M_SIMD::Matrix_M_SIMD(const Vect_M_SIMD &tV0,
							 const Vect_M_SIMD &tV1,
							 const Vect_M_SIMD &tV2,
							 const Vect_M_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}


Matrix_M_SIMD Matrix_M_SIMD::operator * (const Matrix_M_SIMD &mb) const
{
	Vect_M_SIMD Bx = mb.v0;
	Vect_M_SIMD By = mb.v1;
	Vect_M_SIMD Bz = mb.v2;
	Vect_M_SIMD Bw = mb.v3;
		 
	//Vect_M_SIMD Ax;
	//Vect_M_SIMD Ay;
	//Vect_M_SIMD Az;
	//Vect_M_SIMD Aw;

	Matrix_M_SIMD temp;

	Vect_M_SIMD tempRow1;
	Vect_M_SIMD tempRow2;
	Vect_M_SIMD tempRow3;
	Vect_M_SIMD tempRow4;

	//Ax._m = _mm_set1_ps(this->v0.x);
	//Ay._m = _mm_set1_ps(this->v0.y);
	//Az._m = _mm_set1_ps(this->v0.z);
	//Aw._m = _mm_set1_ps(this->v0.w);
	temp.v0._m = _mm_mul_ps(_mm_set1_ps(this->v0.x) , Bx._m);
	temp.v1._m = _mm_mul_ps(_mm_set1_ps(this->v0.y) , By._m);
	temp.v2._m = _mm_mul_ps(_mm_set1_ps(this->v0.z) , Bz._m);
	temp.v3._m = _mm_mul_ps(_mm_set1_ps(this->v0.w) , Bw._m);
	tempRow1._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	/*Ax._m = _mm_set1_ps(this->v1.x);
	Ay._m = _mm_set1_ps(this->v1.y);
	Az._m = _mm_set1_ps(this->v1.z);
	Aw._m = _mm_set1_ps(this->v1.w);*/
	temp.v0._m = _mm_mul_ps(_mm_set1_ps(this->v1.x), Bx._m);
	temp.v1._m = _mm_mul_ps(_mm_set1_ps(this->v1.y), By._m);
	temp.v2._m = _mm_mul_ps(_mm_set1_ps(this->v1.z), Bz._m);
	temp.v3._m = _mm_mul_ps(_mm_set1_ps(this->v1.w), Bw._m);
	tempRow2._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	/*Ax._m = _mm_set1_ps(this->v2.x);
	Ay._m = _mm_set1_ps(this->v2.y);
	Az._m = _mm_set1_ps(this->v2.z);
	Aw._m = _mm_set1_ps(this->v2.w);*/
	temp.v0._m = _mm_mul_ps(_mm_set1_ps(this->v2.x), Bx._m);
	temp.v1._m = _mm_mul_ps(_mm_set1_ps(this->v2.y), By._m);
	temp.v2._m = _mm_mul_ps(_mm_set1_ps(this->v2.z), Bz._m);
	temp.v3._m = _mm_mul_ps(_mm_set1_ps(this->v2.w), Bw._m);
	tempRow3._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	//Ax._m = _mm_set1_ps(this->v3.x);
	//Ay._m = _mm_set1_ps(this->v3.y);
	//Az._m = _mm_set1_ps(this->v3.z);
	//Aw._m = _mm_set1_ps(this->v3.w);
	temp.v0._m = _mm_mul_ps(_mm_set1_ps(this->v3.x), Bx._m);
	temp.v1._m = _mm_mul_ps(_mm_set1_ps(this->v3.y), By._m);
	temp.v2._m = _mm_mul_ps(_mm_set1_ps(this->v3.z), Bz._m);
	temp.v3._m = _mm_mul_ps(_mm_set1_ps(this->v3.w), Bw._m);
	tempRow4._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	return Matrix_M_SIMD(tempRow1, tempRow2, tempRow3, tempRow4);
}


// ---  End of File ---------------
