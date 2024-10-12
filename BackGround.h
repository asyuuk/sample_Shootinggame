#pragma once
#include"Task.h"
#include<memory>
class BackGround : public Task
{
public:
	
	BackGround();
	virtual ~BackGround();
	void draw() override;
	void drawback();
	bool update()override;
	float& GetX() { return *_x; }
	float& GetY() { return *_y; }
	float& SetX(float x) { *_x = x; }
	float& SetY(float y) { *_y = y; }
private:
	std::unique_ptr<float>_x;
	std::unique_ptr<float>_y;
	std::unique_ptr<int>handle;
	std::unique_ptr<int>handlemake;
};

