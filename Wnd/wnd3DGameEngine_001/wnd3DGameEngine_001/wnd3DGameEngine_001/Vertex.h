#pragma once
class Vertex
{
public:
	float x;
	float y;
	float z;
	float w; //������ǥ

public:
	Vertex() {};
	Vertex(float vx, float vy, float vz) { x = vx; y = vy; z = vz; w = 1.f; }
};

