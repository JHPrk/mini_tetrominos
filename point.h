#pragma once
using namespace std;


class Point
{
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
protected:
	int x;
	int y;
};

class FieldPoint : public Point
{
public:
	FieldPoint(int width, int height, int x, int y) : Point(x, y)
	{
		this->width = width;
		this->height = height;
	}
	void moveDownPoint()
	{
		if(checkBorder(x, y + 1))
			y++;
	}
	void moveUpPoint()
	{
		if (checkBorder(x, y - 1))
			y--;
	}
	void moveRightPoint()
	{
		if (checkBorder(x + 1, y))
			x++;
	}
	void moveLeftPoint()
	{
		if (checkBorder(x - 1, y))
			x--;
	}
	bool checkBorder(int x, int y)
	{
		return (x > width || x < 0 || y > height || y < height);
	}

protected:
	int width;
	int height;
};