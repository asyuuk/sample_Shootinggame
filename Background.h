#pragma once

class Background
{
public:
	void SetDraw();
	void Draw() const;
	void DrawEnd();
	float *_x;
	float _y;
	int handle,graphhandle;

};


