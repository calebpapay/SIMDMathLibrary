//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"

Vect_vM_SIMD::Vect_vM_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

//------------------------------
// For No proxy:
//------------------------------

Vect_vM_SIMD Vect_vM_SIMD::operator * (const Matrix_vM_SIMD &ma) const
{
	Vect_vM_SIMD v;
	Matrix_vM_SIMD holder;
	Matrix_vM_SIMD temp;

	holder.v0._m = _mm_set1_ps(this->x);
	holder.v1._m = _mm_set1_ps(this->y);
	holder.v2._m = _mm_set1_ps(this->z);
	holder.v3._m = _mm_set1_ps(this->w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, ma.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, ma.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, ma.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, ma.v3._m);

	v._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	return v;
};


// ---  End of File ---------------


