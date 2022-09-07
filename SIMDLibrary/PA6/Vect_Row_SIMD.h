//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Vect_Row_SIMD_H
#define Vect_Row_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix_Row_SIMD;

// -----------------------------------------------------------------------
// Rules: 
//    Implement for Row Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline vM operator * (const Vect_Row_SIMD &v, const Matrix_Row_SIMD &m)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Vect_Row_SIMD
{
public:
	Vect_Row_SIMD() = default;
	Vect_Row_SIMD(const Vect_Row_SIMD &tmp) = default;
	Vect_Row_SIMD &operator = (const Vect_Row_SIMD &tmp) = default;
	~Vect_Row_SIMD() = default;

	Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw);


	
public:

	// anonymous union
	union
	{
		__m128	_m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};

};

struct VmulM1
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;

	VmulM1(const Vect_Row_SIMD& t1, const Matrix_Row_SIMD& t2)
		:v(t1), m1(t2) {};

	operator Vect_Row_SIMD();
};
inline VmulM1 operator *(const Vect_Row_SIMD& a1, const Matrix_Row_SIMD& a2)
{
	return VmulM1(a1, a2);
};


struct VmulM2
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;

	VmulM2(const VmulM1& t1, const Matrix_Row_SIMD& t2)
		:v(t1.v), m1(t1.m1), m2(t2) {};

	operator Vect_Row_SIMD();
	//{
	//	return Vect_Row_SIMD(v * m1 * m2);
	//}

};
inline VmulM2 operator *(const VmulM1& a1, const Matrix_Row_SIMD& a2)
{
	return VmulM2(a1, a2);
};


struct VmulM3
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;

	VmulM3(const VmulM2& t1, const Matrix_Row_SIMD& t2)
		:v(t1.v), m1(t1.m1), m2(t1.m2), m3(t2) {};

	operator Vect_Row_SIMD();
	/*{
		return Vect_Row_SIMD(v * m1 * m2 * m3);
	}*/

};
inline VmulM3 operator *(const VmulM2& a1, const Matrix_Row_SIMD& a2)
{
	return VmulM3(a1, a2);
};


struct VmulM4
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;
	const Matrix_Row_SIMD& m4;

	VmulM4(const VmulM3& t1, const Matrix_Row_SIMD& t2)
		:v(t1.v), m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t2) {};

	operator Vect_Row_SIMD();
	/*{
		return Vect_Row_SIMD(v * m1 * m2 * m3 * m4);
	}*/

};
inline VmulM4 operator *(const VmulM3& a1, const Matrix_Row_SIMD& a2)
{
	return VmulM4(a1, a2);
};

struct VmulM5
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;
	const Matrix_Row_SIMD& m4;
	const Matrix_Row_SIMD& m5;

	VmulM5(const VmulM4& t1, const Matrix_Row_SIMD& t2)
		:v(t1.v), m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t2) {};

	operator Vect_Row_SIMD();
	/*{
		return Vect_Row_SIMD(v * m1 * m2 * m3 * m4 * m5);
	}*/

};
inline VmulM5 operator *(const VmulM4& a1, const Matrix_Row_SIMD& a2)
{
	return VmulM5(a1, a2);
};


#endif

// ---  End of File ---------------
