#pragma once
#include <vector>

class Node
{
private:
	int id;
	double volt;

public:
	Node(int id);

	int getId() const;
	
	double getVolt() const;

	void setVolt(double volt);
};

