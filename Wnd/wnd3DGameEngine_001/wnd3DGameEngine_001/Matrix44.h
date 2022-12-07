#pragma once
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
	void Move(float dx, float dy);//이동행렬
	void Scale(float size);//크기변환행렬
	void Rotate(float radian);//회전행렬 //라디안
	void Rotate(int tho);//회전행렬		//각도

	Matrix44 Multiply(Matrix44 mat);

};

