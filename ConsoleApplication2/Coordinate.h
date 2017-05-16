#ifndef COORDINATE_H
#define COORDINATE_H
#include<ostream>
using namespace std;
class Coordinate
{
	friend ostream &operator<<(ostream &out, Coordinate &coor);
public:
	Coordinate(){}
	Coordinate(int x, int y);
	void printCoordinate();

private:
	int m_iX;
	int m_iY;

};

#endif