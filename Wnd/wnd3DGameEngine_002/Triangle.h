#pragma once
#include "Vertex.h"
class Triangle
{
public:
	union {
		struct {
			Vertex v1;
			Vertex v2;
			Vertex v3;
		};
		Vertex V[3];
	};
	int idx[3];


public:
	Triangle();
	~Triangle();

	void Set(Vertex v1, Vertex v2, Vertex v3, int i0, int i1, int i2);
	void SetVertex(Vertex v1, Vertex v2, Vertex v3);
	void SetIndex(int i0, int i1, int i2);
	void Draw(int cx, int cy);
};

