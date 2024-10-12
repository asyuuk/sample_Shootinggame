#pragma once
#include<memory>

class SystemMain final
{
public:
	SystemMain();
	~SystemMain() = default;
	bool initialize()const;
	void finalize() const;
	void main()const ;
private:
	std::unique_ptr<int>handle;
};

