//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Mv_SIMD.h"
#include "Matrix_Mv_SIMD.h"

Matrix_Mv_SIMD::Matrix_Mv_SIMD(const Vect_Mv_SIMD &tV0,
							   const Vect_Mv_SIMD &tV1,
							   const Vect_Mv_SIMD &tV2,
							   const Vect_Mv_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}


Vect_Mv_SIMD Matrix_Mv_SIMD::operator * (const Vect_Mv_SIMD &v) const
{
	Vect_Mv_SIMD tX;
	Vect_Mv_SIMD tY;
	Vect_Mv_SIMD tZ;
	Vect_Mv_SIMD tW;

	Matrix_Mv_SIMD m = *this;


	tX._m = _mm_shuffle_ps(m.v0._m, m.v2._m, _MM_SHUFFLE(1, 0, 1, 0));
	tZ._m = _mm_shuffle_ps(m.v0._m, m.v2._m, _MM_SHUFFLE(3, 2, 3, 2));
	tY._m = _mm_shuffle_ps(m.v1._m, m.v3._m, _MM_SHUFFLE(1, 0, 1, 0));
	tW._m = _mm_shuffle_ps(m.v1._m, m.v3._m, _MM_SHUFFLE(3, 2, 3, 2));


	Matrix_Mv_SIMD temp;
	Matrix_Mv_SIMD holder;

	holder.v0._m = _mm_set1_ps(v.x);
	holder.v1._m = _mm_set1_ps(v.y);
	holder.v2._m = _mm_set1_ps(v.z);
	holder.v3._m = _mm_set1_ps(v.w);

	Vect_Mv_SIMD X;
	Vect_Mv_SIMD Y;
	Vect_Mv_SIMD Z;
	Vect_Mv_SIMD W;

	X._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(2, 0, 2, 0));
	Y._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(3, 1, 3, 1));
	Z._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(2, 0, 2, 0));
	W._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(3, 1, 3, 1));
	
	X._m = _mm_shuffle_ps(X._m, X._m, _MM_SHUFFLE(3, 1, 2, 0));
	temp.v0._m = _mm_mul_ps(holder.v0._m, X._m);
	Y._m = _mm_shuffle_ps(Y._m, Y._m, _MM_SHUFFLE(3, 1, 2, 0));
	temp.v1._m = _mm_mul_ps(holder.v1._m, Y._m);


	Z._m = _mm_shuffle_ps(Z._m, Z._m, _MM_SHUFFLE(3, 1, 2, 0));
	temp.v2._m = _mm_mul_ps(holder.v2._m, Z._m);
	W._m = _mm_shuffle_ps(W._m, W._m, _MM_SHUFFLE(3, 1, 2, 0));
	temp.v3._m = _mm_mul_ps(holder.v3._m, W._m);
	
	Vect_Mv_SIMD vb;
	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));
	
	return vb;
}


// ---  End of File ---------------
