#pragma once
#include "Vertex.h"
class Matrix44
{
public:
	union 
	{
		struct {
			float m11, m12, m13, m14;
			float m21, m22, m23, m24;
			float m31, m32, m33, m34;
			float m41, m42, m43, m44;
		};
		float M[4][4];
	};
	Matrix44();
	~Matrix44();

	void Zero();//영행렬
	void Identity();//단위행렬
	void TransLate(float dx, float dy, float dz);//이동변환 행렬
	void Scale(float size);//크기변환행렬
	void RotateX(int tho);//회전행렬
	void RotateY(int tho);//회전행렬
	void RotateZ(int tho);//회전행렬

	Vertex Transform(Vertex v);
	Matrix44 Multiply(Matrix44 mat);
};

