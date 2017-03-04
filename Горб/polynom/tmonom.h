#ifndef __TMONOM_H__
#define __TMONOM_H__

#include <string>
#include <iostream>


#define OVER_IND 999

using namespace std;

class TMonom
{
private:
	int consta;
	int index;
public:
	TMonom();
	TMonom(int _c, int _i);
	TMonom GetCopy() const;
	int GetConsta() const;
	int GetIndex() const;
	void SetConsta(const int _c);
	void SetIndex(const int _i);
	TMonom& operator=(const TMonom &_enter);
	TMonom operator+(const TMonom &_enter);
	TMonom operator-(const TMonom &_enter);
	TMonom operator*(const TMonom &_enter);
	TMonom operator/(const TMonom &_enter); //to hard...
	bool operator==(const TMonom &_enter) const;
	bool operator!=(const TMonom &_enter) const;
};

#endif
