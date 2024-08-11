#pragma once
class AbstructScene
{
public:
	AbstructScene()=default;
	~AbstructScene() = default;
	virtual void update() = 0;
	virtual void draw()const = 0;
};

