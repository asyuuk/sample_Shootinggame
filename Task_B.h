#pragma once
class Task_B
{
public:
	Task_B() = default;
	virtual ~Task_B() = default;
	virtual bool Initialize(float _x, float _y) = 0;
	virtual bool update(float _x, float _y) = 0;
	virtual void Draw()const = 0;
	
};