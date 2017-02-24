#include "tpolinom.h"

//system fuctions:

inline void TPolinom::EraseTrash(string & enter)
{
	for (register int i = 0; i < enter.length(); i++)
	{
		switch (enter[i])
		{
			case ('X'):
			{
				enter[i] = 'x';
				break;
			}
			case ('Y'):
			{
				enter[i] = 'y';
				break;
			}
			case ('Z'):
			{
				enter[i] = 'z';
				break;
			}
			++i;
		}
		if ((enter[i] > 0 && enter[i] <= 42) || (enter[i] >= 58 && enter[i] <= 96) || (enter[i] >= 123 && enter[i] <= 127))
			enter.erase(i--, 1);
	}
	//put space for work algorythm:
	enter.insert(0,1,' ');
}

inline bool TPolinom::IsDigit(int i,const string &a)
{
	if (a[i] >= '0' && a[i] <= '9')
		return true;
	else return false;
};

inline bool TPolinom::IsChar(int i, const string &a)
{
	if (a[i]>='A' && a[i]<='z') 
		return true;
	else return false;
};

//end of system functions

TPolinom::TPolinom()
{
	TMonom p(0,-1);
	self.InsFirst(p);
};

TPolinom::TPolinom(const string &enter)
{
	TMonom p(0, -1);
	self.InsFirst(p);
	string pnom = enter;
	EraseTrash(pnom);
	register int k = 0, j = 0, coeff, ind, a, b, c;
	register char digtmp[BIT];
	bool negative(false);
	for (register int i = 1; i < pnom.length(); i++)
	{
		if (pnom[i] == 45) ++i; //if gotcha '-' go next
		if (IsDigit(i, pnom))
		{ //if digit
			j = i;
			k = 0;
			if (pnom[i - 1] == 45)	negative = true;
			while (IsDigit(j, pnom))
			{
				digtmp[k] = pnom[j++];
				digtmp[++k] = '\0';
			}
			coeff = atoi(digtmp);
			if (negative)
			{
				coeff *= -1;
				negative = false;
			}
			i = j;
			
		}
		while (pnom[i] != 43 && pnom[i] != 45 && i!=pnom.size())
			{
			if (IsChar(i, pnom)) //skip char
				++i;
			// to degree
				j = i;
				k = 0;
				while (IsDigit(j, pnom))
				{
					digtmp[k] = pnom[j++];
					digtmp[++k] = '\0';
				}
				switch (pnom[i - 1])
				{
					case('x'):
					{
						a= atoi(digtmp);
						break;
					}
					case('y'):
					{
						b = atoi(digtmp);
						break;
					}
					case('z'):
					{
						c = atoi(digtmp);
						break;
					}
				}
				i = j;
			}
		ind = a * 100 + b * 10 + c;
		TMonom p(coeff, ind);
		self.InsLast(p);
	}
}

bool TPolinom::operator==(TPolinom &_enter)
{
	if (GetLen() != _enter.GetLen()) return false;
	for (register int i = 0; i < _enter.GetLen(); i++)
	{
		if (self.GetVal(i) != _enter.GetVal(i)) return false;
	} return true;
};

bool TPolinom::operator!=(TPolinom &_enter)
{
	return (!(*this==_enter));
};

TPolinom& TPolinom::operator=(TPolinom _enter)
{
	self.Delete();
	for (register int i = 0; i < _enter.GetLen(); i++)
		self.Ins(i, _enter.GetVal(i));
	return *this;
};

TPolinom& TPolinom::dif()
{
	return *this;
};

TPolinom& TPolinom::integrate()
{
	return *this;
};

TPolinom TPolinom::operator+(TPolinom &_enter)
{
	TPolinom res;
	for (register int i = 1; i < _enter.GetLen(); i++)
	{
		if (self.GetVal(i).GetIndex() != _enter.GetVal(i).GetIndex())
		{
			res.Ins(i, self.GetVal(i));
			res.Ins(i+1, _enter.GetVal(i+1));
		}
		else
		{
			TMonom a = self.GetVal(i);
			res.Ins(i, a + _enter.GetVal(i));
		}
	}
	return res;
};

TPolinom TPolinom::operator-(TPolinom &_enter)
{
	TPolinom res;
	for (register int i = 1; i < _enter.GetLen(); i++)
	{
		if (self.GetVal(i).GetIndex() != _enter.GetVal(i).GetIndex())
		{
			res.Ins(i, self.GetVal(i));
			res.Ins(i + 1, _enter.GetVal(i + 1));
		}
		else
		{
			TMonom a = self.GetVal(i);
			res.Ins(i, a - _enter.GetVal(i));
		}
	}
	return res;
};

TPolinom TPolinom::operator*(TPolinom &_enter)
{
	TPolinom res;
	register int k = 0;
	for (register int i = 1; i < _enter.GetLen(); i++)
	{
		TMonom a = self.GetVal(i);
		for (register int j = i; j < _enter.GetLen(); j++) //multiply by fountain
			res.Ins(k++, a * _enter.GetVal(j));
	}
	return res;
}
TPolinom TPolinom::operator/(TPolinom &_enter)
{
	return TPolinom();
};
