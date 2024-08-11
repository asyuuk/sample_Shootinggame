#pragma once
#include<vector>
#include"Define.h"
class Task
{
public:
	Task()=default;
	virtual ~Task() = default;
	virtual void Initialize()=0;
	virtual bool Update()=0;
	virtual void Draw() = 0;

protected:
	bool IsInside()const;

public:
	int _x;
	int _y;
	int  x[256];
	int  y[256];
	int  _bx[PlayerShot];
	int  _by[PlayerShot];
	bool ShotValid[PlayerShot];
	
	
	int _W;
	int _H;
	int Graph;
	int Graphs[2];
	int BulletGraph;
	int count;
	bool visible;
	int framecount=0;
	int animationFrame=0;
	int HP[256];
	int Attack;
	int _BW;
	int _BH;
	int Time;
	int i;

	std::vector<int>Graphs_s;
	std::vector<int>Graphs_sp;
};

struct EnemyData
{
	int type;
	int BulletType;
	int MovePattern;
	int ShotPattern;
	int AppearTime;
	int StopTime;
};