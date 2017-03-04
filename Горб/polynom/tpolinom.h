#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#include <string>
#include <iostream>
#include "tlist.h"
#include "tmonom.h"


#define MCON 150
#define BIT 3
#define MAX_MON 12

using namespace std;

class TPolinom
{
private:
	TList<TMonom> self;
	void EraseTrash(string &enter);
	bool IsDigit(int i,const string &a);
	bool IsChar(int i,const string &a);
	void Optimize();
public:
	TPolinom();
	TPolinom(const TPolinom &_enter);
	TPolinom(const string &enter);
	short int GetLen() const { return self.GetLen(); };
	TMonom GetVal(const int pos) const { return self.GetVal(pos); } //get copy
	void SetVal(const int pos, TMonom _enter) { self.SetVal(pos, _enter); }
	void Ins(const int pos, TMonom _enter) { self.Ins(pos, _enter); }
	bool operator==(const TPolinom &_enter) const;
	bool operator!=(const TPolinom &_enter) const;
	TPolinom& operator=(const TPolinom &_enter);
	TPolinom& dif();
	TPolinom& integrate();
	TPolinom operator+(const TPolinom &_enter);
	TPolinom operator-(const TPolinom &_enter);
	TPolinom operator*(const TPolinom &_enter);
	TPolinom operator/(const TPolinom &_enter);
	TPolinom operator*(int _value);
	string ToString() const; //all polynom to string
	string ToString(int pos) const; //pos-monom to stirng
	double Calculate(int _x, int _y, int _z) const;
	friend ostream& operator<<(ostream &out, const TPolinom &_enter);

};


#endif
