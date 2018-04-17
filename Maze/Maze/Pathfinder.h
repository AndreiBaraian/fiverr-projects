#pragma once
#include<string>
using namespace std;
class Pathfinder
{
public:
	Pathfinder() {}
	virtual ~Pathfinder() {}
	virtual string toString() const = 0;
};