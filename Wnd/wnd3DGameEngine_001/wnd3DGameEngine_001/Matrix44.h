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

	void Zero();//�����
	void Identity();//�������
	void Move(float dx, float dy);//�̵����
	void Scale(float size);//ũ�⺯ȯ���
	void Rotate(float radian);//ȸ����� //����
	void Rotate(int tho);//ȸ�����		//����

	Matrix44 Multiply(Matrix44 mat);

};

