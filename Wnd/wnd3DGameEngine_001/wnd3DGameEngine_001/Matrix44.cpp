#include "Matrix44.h"
Matrix44::Matrix44()
{

}
Matrix44::~Matrix44()
{

}

void Matrix44::Zero()
{
	m11 = 0.f, m12 = 0.f, m13 = 0.f, m14 = 0.f;
	m21 = 0.f, m22 = 0.f, m23 = 0.f, m24 = 0.f;
	m31 = 0.f, m32 = 0.f, m33 = 0.f, m34 = 0.f;
	m41 = 0.f, m42 = 0.f, m43 = 0.f, m44 = 0.f;
}
void Matrix44::Identity()
{
	m11 = 1.f, m12 = 0.f, m13 = 0.f, m14 = 0.f;
	m21 = 0.f, m22 = 1.f, m23 = 0.f, m24 = 0.f;
	m31 = 0.f, m32 = 0.f, m33 = 1.f, m34 = 0.f;
	m41 = 0.f, m42 = 0.f, m43 = 0.f, m44 = 1.f;
}
Matrix44 Matrix44::Multiply(Matrix44 mat)
{
	Matrix44 Temp;
	Temp.m11 = m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41;
	Temp.m12 = m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42;
	Temp.m13 = m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43;
	Temp.m14 = m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44;

	Temp.m21 = m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41;
	Temp.m22 = m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42;
	Temp.m23 = m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43;
	Temp.m24 = m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44;

	Temp.m31 = m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41;
	Temp.m32 = m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42;
	Temp.m33 = m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43;
	Temp.m34 = m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44;

	Temp.m41 = m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41;
	Temp.m42 = m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42;
	Temp.m43 = m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43;
	Temp.m44 = m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44;
}