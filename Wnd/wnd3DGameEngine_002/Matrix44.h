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

	void Zero();//�����
	void Identity();//�������
	void TransLate(float dx, float dy, float dz);//�̵���ȯ ���
	void Scale(float size);//ũ�⺯ȯ���
	void RotateX(int tho);//ȸ�����
	void RotateY(int tho);//ȸ�����
	void RotateZ(int tho);//ȸ�����

	Vertex Transform(Vertex v);
	Matrix44 Multiply(Matrix44 mat);
};

