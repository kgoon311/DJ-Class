#pragma once
class Mesh
{
protected:
	int m_nVertex; //꼭지점이 수
	int m_nTriangle; //삼각형의 수
	Vertex* m_pVertex;
	int* m_pTI;
	//Triangle* m_pTriangle;

	Matrix44 m_Mat;

public:
	Mesh(){}
	virtual ~Mesh(){}

	virtual void SetMatrix(Matrix44 mat) { m_Mat = mat; }

	//초기화
	virtual void Initialize() = 0;
	//그리기
	virtual void Render() = 0;
	//지우기
	virtual void Release(){}
};

