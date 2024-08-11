#pragma once

class SystemMain 
{
public:
	SystemMain() = default;
	~SystemMain() = default;
	bool Initialize() const;
	void finalize() const;
	void main()const;
};

