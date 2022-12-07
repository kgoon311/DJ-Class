#include "Triangle.h"
#include "wndGdi.h"
#include "GameEngineRun.h" //YellowDot 사용하려 포함함

Triangle::Triangle()
{

}

Triangle::~Triangle()
{

}

void Triangle::Set(Vertex v1, Vertex v2, Vertex v3, int i0, int i1, int i2)
{
	SetVertex(v1, v2, v3);
	SetIndex(i0, i1, i2);
}

void Triangle::SetVertex(Vertex v1, Vertex v2, Vertex v3)
{
	this->V[0] = v1;
	this->v2 = v2;
	this->V[2] = v3;
}

void Triangle::SetIndex(int i0, int i1, int i2)
{
	this->idx[0] = i0;
	this->idx[1] = i1;
	this->idx[2] = i2;
}

void Triangle::Draw(int cx, int cy)
{
	gdi->GreenPen();
	//	for (int i = 0; i < 3; i++)
	{
		gdi->Line(v1.x + cx, -v1.y + cy, v2.x + cx, -v2.y + cy);
		gdi->Line(v2.x + cx, -v2.y + cy, v3.x + cx, -v3.y + cy);
		gdi->Line(v3.x + cx, -v3.y + cy, v1.x + cx, -v1.y + cy);
	}
	YellowDot(v1.x + cx, -v1.y + cy);
	YellowDot(v2.x + cx, -v2.y + cy);
	YellowDot(v3.x + cx, -v3.y + cy);
}