#pragma once
#include "framework.h"
#include "Tetra.h"

const int TRIANGLE = 3;

Tetra::Tetra(){
}
Tetra::~Tetra(){
}

void Tetra::Initialize()
{
	this->m_nVertex = 4;
	this->m_nTriangle = 4;
	this->m_pVertex = new Vertex[m_nVertex];
	this->m_pSVertex = new Vertex[m_nVertex];
	this->m_pTI = new int[m_nTriangle * TRIANGLE];

	this->m_pVertex[0] = Vertex(   0.f,  100.f,   0.f);
	this->m_pVertex[1] = Vertex(-100.f, -100.f,   0.f);
	this->m_pVertex[2] = Vertex( 100.f, -100.f,   0.f);
	this->m_pVertex[3] = Vertex(   0.f,    0.f, 100.f);

	this->m_pTI[0] = 0; this->m_pTI[1] = 1; this->m_pTI[2] = 3;
	this->m_pTI[3] = 0; this->m_pTI[4] = 3; this->m_pTI[5] = 2;
	this->m_pTI[6] = 1; this->m_pTI[7] = 2; this->m_pTI[8] = 3;
	this->m_pTI[9] = 0; this->m_pTI[10] = 2; this->m_pTI[11] = 1;
}
void Tetra::Render()
{
	gdi->GreenPen();

	for (int i = 0; i < m_nVertex; i++)
	{
		m_pSVertex[i] = this->m_Mat.Transform(m_pSVertex[i]);
	}

	for (int i = 0; i < m_nTriangle * TRIANGLE; i += TRIANGLE)
	{
		gdi->Line(m_pSVertex[m_pTI[i + 0]].x,  m_pSVertex[m_pTI[i + 0]].y,
				  m_pSVertex[m_pTI[i + 1]].x,  m_pSVertex[m_pTI[i + 1]].y);
		gdi->Line(m_pSVertex[m_pTI[i + 1]].x,  m_pSVertex[m_pTI[i + 1]].y,
				  m_pSVertex[m_pTI[i + 2]].x,  m_pSVertex[m_pTI[i + 2]].y);
		gdi->Line(m_pSVertex[m_pTI[i + 2]].x,  m_pSVertex[m_pTI[i + 2]].y,
				  m_pSVertex[m_pTI[i + 0]].x,  m_pSVertex[m_pTI[i + 0]].y);
	}

	for (int i = 0; i < m_nVertex; i++)
	{
		YellowDot(m_pSVertex[i].x, m_pSVertex[i].y);
	}
}
void Tetra::Release()
{
	delete[] this->m_pVertex;
}