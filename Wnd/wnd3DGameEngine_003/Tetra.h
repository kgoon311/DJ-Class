#pragma once
#include "Mesh.h"
class Tetra : public Mesh
{
private:
	Vertex* m_pSVertex;
public:
	Tetra();
	virtual ~Tetra();

	void Initialize();
	void Render();
	void Release();

};

