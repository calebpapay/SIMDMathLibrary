//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Matrix_Col_SIMD_H
#define Matrix_Col_SIMD_H

#include "Vect_Col_SIMD.h"
   
// -----------------------------------------------------------------------
// Rules: 
//    Implement for Col Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline MM operator * (const Matrix_Col_SIMD &m, const Matrix_Col_SIMD &n)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Matrix_Col_SIMD
{
public:
	Matrix_Col_SIMD() = default;
	Matrix_Col_SIMD(const Matrix_Col_SIMD &tmp) = default;
	Matrix_Col_SIMD &operator=(const Matrix_Col_SIMD &tmp) = default;
	~Matrix_Col_SIMD() = default;

	Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
					const Vect_Col_SIMD &tV1,
					const Vect_Col_SIMD &tV2,
					const Vect_Col_SIMD &tV3);

	
	union
	{
		struct
		{
			Vect_Col_SIMD v0;
			Vect_Col_SIMD v1;
			Vect_Col_SIMD v2;
			Vect_Col_SIMD v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

struct MM
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;

	MM (const Matrix_Col_SIMD& t1, const Matrix_Col_SIMD& t2)
		:m1(t1), m2(t2) {};

};
inline MM operator *(const Matrix_Col_SIMD& a1, const Matrix_Col_SIMD& a2)
{
	return MM(a1, a2);
};


struct MM2
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;

	MM2(const MM& t1, const Matrix_Col_SIMD& t2)
		:m1(t1.m1), m2(t1.m2), m3(t2) {};
};
inline MM2 operator *(const MM& a1, const Matrix_Col_SIMD& a2)
{
	return MM2(a1, a2);
};


struct MM3
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;
	const Matrix_Col_SIMD& m4;

	MM3(const MM2& t1, const Matrix_Col_SIMD& t2)
		:m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t2) {};
};
inline MM3 operator *(const MM2& a1, const Matrix_Col_SIMD& a2)
{
	return MM3(a1, a2);
};


struct MM4
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;
	const Matrix_Col_SIMD& m4;
	const Matrix_Col_SIMD& m5;

	MM4(const MM3& t1, const Matrix_Col_SIMD& t2)
		:m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t2) {};

};
inline MM4 operator *(const MM3& a1, const Matrix_Col_SIMD& a2)
{
	return MM4(a1, a2);
};


struct MM5
{
	const Vect_Col_SIMD& v;
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;
	const Matrix_Col_SIMD& m4;
	const Matrix_Col_SIMD& m5;

	MM5(const Vect_Col_SIMD& t2, const MM4& t1)
		:v(t2), m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t1.m5) {};

	operator Vect_Col_SIMD();
};
inline MM5 operator *(const MM4& a1, const Vect_Col_SIMD& a2)
{
	return MM5(a2, a1);
};

#endif

// ---  End of File ---------------
