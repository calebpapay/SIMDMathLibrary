//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"

Vect_Row_SIMD::Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

VmulM1::operator Vect_Row_SIMD()
{
	Vect_Row_SIMD vb;
	Matrix_Row_SIMD holder;
	Matrix_Row_SIMD temp;

	holder.v0._m = _mm_set1_ps(v.x);
	holder.v1._m = _mm_set1_ps(v.y);
	holder.v2._m = _mm_set1_ps(v.z);
	holder.v3._m = _mm_set1_ps(v.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m1.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m1.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m1.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m1.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));
	return vb;
}

VmulM2::operator Vect_Row_SIMD()
{
	Vect_Row_SIMD vb;
	Matrix_Row_SIMD holder;
	Matrix_Row_SIMD temp;

	holder.v0._m = _mm_set1_ps(v.x);
	holder.v1._m = _mm_set1_ps(v.y);
	holder.v2._m = _mm_set1_ps(v.z);
	holder.v3._m = _mm_set1_ps(v.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m1.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m1.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m1.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m1.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m2.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m2.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m2.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m2.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));
	return vb;
}

VmulM3::operator Vect_Row_SIMD()
{
	Vect_Row_SIMD vb;
	Matrix_Row_SIMD holder;
	Matrix_Row_SIMD temp;

	holder.v0._m = _mm_set1_ps(v.x);
	holder.v1._m = _mm_set1_ps(v.y);
	holder.v2._m = _mm_set1_ps(v.z);
	holder.v3._m = _mm_set1_ps(v.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m1.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m1.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m1.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m1.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m2.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m2.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m2.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m2.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m3.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m3.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m3.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m3.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));
	return vb;
}

VmulM4::operator Vect_Row_SIMD()
{
	Vect_Row_SIMD vb;
	Matrix_Row_SIMD holder;
	Matrix_Row_SIMD temp;

	holder.v0._m = _mm_set1_ps(v.x);
	holder.v1._m = _mm_set1_ps(v.y);
	holder.v2._m = _mm_set1_ps(v.z);
	holder.v3._m = _mm_set1_ps(v.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m1.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m1.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m1.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m1.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m2.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m2.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m2.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m2.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m3.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m3.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m3.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m3.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m4.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m4.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m4.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m4.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));


	return vb;
}

VmulM5::operator Vect_Row_SIMD()
{
	Vect_Row_SIMD vb;
	Matrix_Row_SIMD holder;
	Matrix_Row_SIMD temp;

	holder.v0._m = _mm_set1_ps(v.x);
	holder.v1._m = _mm_set1_ps(v.y);
	holder.v2._m = _mm_set1_ps(v.z);
	holder.v3._m = _mm_set1_ps(v.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m1.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m1.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m1.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m1.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m2.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m2.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m2.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m2.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m3.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m3.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m3.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m3.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m4.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m4.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m4.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m4.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	holder.v0._m = _mm_set1_ps(vb.x);
	holder.v1._m = _mm_set1_ps(vb.y);
	holder.v2._m = _mm_set1_ps(vb.z);
	holder.v3._m = _mm_set1_ps(vb.w);

	temp.v0._m = _mm_mul_ps(holder.v0._m, m5.v0._m);
	temp.v1._m = _mm_mul_ps(holder.v1._m, m5.v1._m);
	temp.v2._m = _mm_mul_ps(holder.v2._m, m5.v2._m);
	temp.v3._m = _mm_mul_ps(holder.v3._m, m5.v3._m);

	vb._m = _mm_add_ps(temp.v0._m, _mm_add_ps(temp.v1._m, _mm_add_ps(temp.v2._m, temp.v3._m)));

	return vb;
}
// ---  End of File ---------------


