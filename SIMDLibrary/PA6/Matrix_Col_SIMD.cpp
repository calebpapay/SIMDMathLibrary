//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
								 const Vect_Col_SIMD &tV1,
								 const Vect_Col_SIMD &tV2,
								 const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}



MM5::operator Vect_Col_SIMD()
{
	Vect_Col_SIMD tX;
	Vect_Col_SIMD tY;
	Vect_Col_SIMD tZ;
	Vect_Col_SIMD tW;

	//
	//-------------> m5

	tX._m = _mm_shuffle_ps(m5.v0._m, m5.v2._m, _MM_SHUFFLE(1, 0, 1, 0));
	tZ._m = _mm_shuffle_ps(m5.v0._m, m5.v2._m, _MM_SHUFFLE(3, 2, 3, 2));
	tY._m = _mm_shuffle_ps(m5.v1._m, m5.v3._m, _MM_SHUFFLE(1, 0, 1, 0));
	tW._m = _mm_shuffle_ps(m5.v1._m, m5.v3._m, _MM_SHUFFLE(3, 2, 3, 2));

	Matrix_Col_SIMD temp;
	Matrix_Col_SIMD holder;

	holder.v0._m = _mm_set1_ps(v.x);
	holder.v1._m = _mm_set1_ps(v.y);
	holder.v2._m = _mm_set1_ps(v.z);
	holder.v3._m = _mm_set1_ps(v.w);

	Vect_Col_SIMD X;
	Vect_Col_SIMD Y;
	Vect_Col_SIMD Z;
	Vect_Col_SIMD W;


	X._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(2, 0, 2, 0));
	Y._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(3, 1, 3, 1));
	Z._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(2, 0, 2, 0));
	W._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(3, 1, 3, 1));

	temp.v0._m = _mm_mul_ps(holder.v0._m, X._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, Y._m);

	temp.v2._m = _mm_mul_ps(holder.v2._m, Z._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, W._m);
	
	Vect_Col_SIMD vb;
	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	//
	//-------------> m4

	tX._m = _mm_shuffle_ps(m4.v0._m, m4.v2._m, _MM_SHUFFLE(1, 0, 1, 0));
	tZ._m = _mm_shuffle_ps(m4.v0._m, m4.v2._m, _MM_SHUFFLE(3, 2, 3, 2));
	tY._m = _mm_shuffle_ps(m4.v1._m, m4.v3._m, _MM_SHUFFLE(1, 0, 1, 0));
	tW._m = _mm_shuffle_ps(m4.v1._m, m4.v3._m, _MM_SHUFFLE(3, 2, 3, 2));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.z);
	holder.v2._m = _mm_set1_ps(vb.y);
	holder.v3._m = _mm_set1_ps(vb.w);


	X._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(2, 0, 2, 0));
	Y._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(3, 1, 3, 1));
	Z._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(2, 0, 2, 0));
	W._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(3, 1, 3, 1));

	temp.v0._m = _mm_mul_ps(holder.v0._m, X._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, Y._m);

	temp.v2._m = _mm_mul_ps(holder.v2._m, Z._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, W._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	//
	//-------------> m3

	tX._m = _mm_shuffle_ps(m3.v0._m, m3.v2._m, _MM_SHUFFLE(1, 0, 1, 0));
	tZ._m = _mm_shuffle_ps(m3.v0._m, m3.v2._m, _MM_SHUFFLE(3, 2, 3, 2));
	tY._m = _mm_shuffle_ps(m3.v1._m, m3.v3._m, _MM_SHUFFLE(1, 0, 1, 0));
	tW._m = _mm_shuffle_ps(m3.v1._m, m3.v3._m, _MM_SHUFFLE(3, 2, 3, 2));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.z);
	holder.v2._m = _mm_set1_ps(vb.y);
	holder.v3._m = _mm_set1_ps(vb.w);



	X._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(2, 0, 2, 0));
	Y._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(3, 1, 3, 1));
	Z._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(2, 0, 2, 0));
	W._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(3, 1, 3, 1));

	temp.v0._m = _mm_mul_ps(holder.v0._m, X._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, Y._m);


	temp.v2._m = _mm_mul_ps(holder.v2._m, Z._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, W._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	//
	//-------------> m2

	tX._m = _mm_shuffle_ps(m2.v0._m, m2.v2._m, _MM_SHUFFLE(1, 0, 1, 0));
	tZ._m = _mm_shuffle_ps(m2.v0._m, m2.v2._m, _MM_SHUFFLE(3, 2, 3, 2));
	tY._m = _mm_shuffle_ps(m2.v1._m, m2.v3._m, _MM_SHUFFLE(1, 0, 1, 0));
	tW._m = _mm_shuffle_ps(m2.v1._m, m2.v3._m, _MM_SHUFFLE(3, 2, 3, 2));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.z);
	holder.v2._m = _mm_set1_ps(vb.y);
	holder.v3._m = _mm_set1_ps(vb.w);



	X._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(2, 0, 2, 0));
	Y._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(3, 1, 3, 1));
	Z._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(2, 0, 2, 0));
	W._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(3, 1, 3, 1));

	temp.v0._m = _mm_mul_ps(holder.v0._m, X._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, Y._m);


	temp.v2._m = _mm_mul_ps(holder.v2._m, Z._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, W._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	//
	//-------------> m1

	tX._m = _mm_shuffle_ps(m1.v0._m, m1.v2._m, _MM_SHUFFLE(1, 0, 1, 0));
	tZ._m = _mm_shuffle_ps(m1.v0._m, m1.v2._m, _MM_SHUFFLE(3, 2, 3, 2));
	tY._m = _mm_shuffle_ps(m1.v1._m, m1.v3._m, _MM_SHUFFLE(1, 0, 1, 0));
	tW._m = _mm_shuffle_ps(m1.v1._m, m1.v3._m, _MM_SHUFFLE(3, 2, 3, 2));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.z);
	holder.v2._m = _mm_set1_ps(vb.y);
	holder.v3._m = _mm_set1_ps(vb.w);

	X._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(2, 0, 2, 0));
	Y._m = _mm_shuffle_ps(tX._m, tY._m, _MM_SHUFFLE(3, 1, 3, 1));
	Z._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(2, 0, 2, 0));
	W._m = _mm_shuffle_ps(tZ._m, tW._m, _MM_SHUFFLE(3, 1, 3, 1));

	temp.v0._m = _mm_mul_ps(holder.v0._m, X._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, Y._m);

	temp.v2._m = _mm_mul_ps(holder.v2._m, Z._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, W._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));
	vb._m = _mm_shuffle_ps(vb._m, vb._m, _MM_SHUFFLE(3, 1, 2, 0));
	return vb;
}
// ---  End of File ---------------
