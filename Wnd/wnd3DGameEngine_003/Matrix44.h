#pragma once
class Matrix44
{
public:
	union {
		struct
		{
			float m11, m12, m13, m14;
			float m21, m22, m23, m24;
			float m31, m32, m33, m34;
			float m41, m42, m43, m44;
		};
		float M[4][4];
	};

public:
	Matrix44();
	~Matrix44();
	void Zero(); //행렬 덧셈 항등원
	void Identity(); //행렬 곱셈 항등원

	void Translate(float dx, float dy, float dz); //이동변환 행렬
	void Scale(float s); //크기변환 행렬
	void RotateX(int Dho); //X축 회전변환 행렬
	void RotateY(int Dho); //Y축 회전변환 행렬
	void RotateZ(int Dho); //Z축 회전변환 행렬

	void ScreenCoordTranslate(int cx, int cy); //좌표계 변화 행렬

	Matrix44 Multiply(Matrix44 mat); //행렬 곱하기 연산자
	Vertex Transform(Vertex v); //Vertex에 행렬식 적용

	void Output(int dx, int dy);
};

