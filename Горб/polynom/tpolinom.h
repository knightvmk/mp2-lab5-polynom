#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#include <string>
#include "tlist.h"
#include "tmonom.h"

#define MCON 150
#define BIT 3

using namespace std;

class TPolinom
{
private:
	TList<TMonom> self;
	void EraseTrash(string &enter);
	bool IsDigit(int i,const string &a);
	bool IsChar(int i,const string &a);
public:
	TPolinom();
	TPolinom(const string &enter);
	int GetLen() const { return self.GetLen() - 1; };
	TMonom GetVal(const int pos) { return self.GetVal(pos); } //get copy
	void SetVal(const int pos, TMonom _enter) { self.SetVal(pos, _enter); }
	void Ins(const int pos, TMonom _enter) { self.Ins(pos, _enter); }
	bool operator==(TPolinom &_enter);
	bool operator!=(TPolinom &_enter);
	TPolinom& operator=(TPolinom _enter);
	TPolinom& dif();
	TPolinom& integrate();
	TPolinom operator+(TPolinom &_enter);
	TPolinom operator-(TPolinom &_enter);
	TPolinom operator*(TPolinom &_enter);
	TPolinom operator/(TPolinom &_enter);

};


#endif
