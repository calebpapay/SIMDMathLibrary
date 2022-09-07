//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_TRIANGLE_SIMD.h"



Vect_TRIANGLE_SIMD::Vect_TRIANGLE_SIMD(const float tx, const float ty, const float tz, const float tw)
	:x(tx),y(ty),z(tz),w(tw)
{

}

float Vect_TRIANGLE_SIMD::Length() const
{
	Vect_TRIANGLE_SIMD A;

	A._m = _mm_mul_ps(this->_m, this->_m);
	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_sqrt_ss(A._m);

	return A.x;
}

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::Cross(const Vect_TRIANGLE_SIMD &R) const
{
	Vect_TRIANGLE_SIMD ret;

	__m128 _A = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 0, 2, 1));
	__m128 _B = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 1, 0, 2));
	__m128 _C = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 0, 2, 1));
	__m128 _D = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 1, 0, 2));
	ret._m = _mm_sub_ps(_mm_mul_ps(_A, _B), _mm_mul_ps(_C, _D));

	return ret;
}

float Vect_TRIANGLE_SIMD::Area(const Vect_TRIANGLE_SIMD &T, const Vect_TRIANGLE_SIMD &R) 
{
	return 0.5f * (T.Cross(R)).Length();;
}


// ---  End of File ---

