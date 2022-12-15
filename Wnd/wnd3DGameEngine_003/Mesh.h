#pragma once
class Mesh
{
protected:
	int m_nVertex; //�������� ��
	int m_nTriangle; //�ﰢ���� ��
	Vertex* m_pVertex;
	int* m_pTI;
	//Triangle* m_pTriangle;

	Matrix44 m_Mat;

public:
	Mesh(){}
	virtual ~Mesh(){}

	virtual void SetMatrix(Matrix44 mat) { m_Mat = mat; }

	//�ʱ�ȭ
	virtual void Initialize() = 0;
	//�׸���
	virtual void Render() = 0;
	//�����
	virtual void Release(){}
};

