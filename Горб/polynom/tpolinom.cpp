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

//end of system functions;

//user methods:

TPolinom::TPolinom()
{
	TMonom p(0,-1);
	self.InsFirst(p);
}

TPolinom::TPolinom(const TPolinom & _enter)
{
	for (register int i = 0; i < _enter.GetLen(); i++)
	{
		self.InsLast(_enter.GetVal(i));
	}
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
		a = b = c = 0;
		TMonom p(coeff, ind);
		self.InsLast(p);
	}
}

bool TPolinom::operator==(const TPolinom &_enter) const
{
	if (self.GetLen() != _enter.GetLen()) return false;
	for (register int i = 0; i < _enter.GetLen(); i++)
	{
		if (self.GetVal(i) != _enter.GetVal(i)) return false;
	} return true;
};

bool TPolinom::operator!=(const TPolinom &_enter) const
{
	return (!(*this==_enter));
};

TPolinom& TPolinom::operator=(const TPolinom &_enter)
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
}

inline void TPolinom::Optimize()
{
	TMonom tmp,work;
	for (register int i = 1; i < self.GetLen(); i++)
	{
		work = self.GetVal(i);
		for (register int j = i; j < self.GetLen(); j++)
		{
			if ((work.GetIndex() == self.GetVal(j).GetIndex()) && (i!=j))
			{
				self.SetVal(i, work + self.GetVal(j));
				self.DelCell(j);
				--j; //check again
			}
		}
	}
};

//overload operators:

TPolinom TPolinom::operator+(const TPolinom &_enter)
{
	TPolinom res;
	for (register int i = 1, j=1; i < _enter.GetLen(); i++,j++)
	{
		if (self.GetVal(i).GetIndex() != _enter.GetVal(i).GetIndex())
		{
			res.Ins(j, _enter.GetVal(i));
			res.Ins(j++, self.GetVal(i));
		}
		else
		{
			res.Ins(j, self.GetVal(i) + _enter.GetVal(i));
		}
	}
	if (self.GetLen() != 2) res.Optimize();
	return res;
};

TPolinom TPolinom::operator-(const TPolinom &_enter)
{
	TPolinom res;
	for (register int i = 1, j = 1; i < _enter.GetLen(); i++, j++)
	{
		if (self.GetVal(i).GetIndex() != _enter.GetVal(i).GetIndex())
		{
			res.Ins(j, _enter.GetVal(i));
			res.Ins(j++, self.GetVal(i));
		}
		else
		{
			res.Ins(j, self.GetVal(i) - _enter.GetVal(i));
		}
	}
	if (self.GetLen() != 2) res.Optimize();
	return res;
};

TPolinom TPolinom::operator*(const TPolinom &_enter)
{
	TPolinom res;
	register int k = 1;
	for (register int i = 1; i < _enter.GetLen(); i++)
	{
		for (register int j = 1; j < _enter.GetLen(); j++) //multiply by fountain
			res.Ins(k++, self.GetVal(i) * _enter.GetVal(j));
	}

	if(self.GetLen()!= 2) res.Optimize();
	return res;
}
TPolinom TPolinom::operator*(int _value)
{
	TPolinom res(*this);
	TMonom work;
	register int w_const;
	for (register int i = 1; i < res.GetLen(); i++)
	{
		work = res.GetVal(i);
	    w_const = work.GetConsta();
		work.SetConsta(w_const*_value);
		res.SetVal(i, work);
	}
	return res;
};

TPolinom TPolinom::operator/(const TPolinom &_enter)
{
	TPolinom res;
	register int k = 1;
	for (register int i = 1; i < _enter.GetLen(); i++)
	{
		for (register int j = i; j < _enter.GetLen(); j++) //divide by fountain
			res.Ins(k++, self.GetVal(i) / _enter.GetVal(j));
	}
	if (self.GetLen() != 2) res.Optimize();
	return res;
};

string TPolinom::ToString() const
{
	string res;
	TMonom work;
	register int a, b, c, index;
	for (register int i = 1; i < self.GetLen(); i++)
	{
		work = self.GetVal(i);
		index = work.GetIndex();
		if (i != 1 && work.GetConsta() >= 0)
			res.push_back('+');
		res += to_string(work.GetConsta());
		{
			a = (int)(index / 100);
			b = (int)((index - a * 100) / 10);
			c = index - a * 100 - b * 10;
		}
		res.push_back('x');
		res+=(to_string(a));
		res.push_back('y');
		res += to_string(b);
		res.push_back('z');
		res+=to_string(c);
	}
	return res;
};

string TPolinom::ToString(int pos) const
{
	if (pos < 1 || pos >= self.GetLen()) throw ("Bad allocate to monom");
	string res;
	TMonom work;
	register int a, b, c, index;
	work = self.GetVal(pos);
	index = work.GetIndex();
	res += to_string(work.GetConsta());
	{
		a = (int)(index / 100);
		b = (int)((index - a * 100) / 10);
		c = index - a * 100 - b * 10;
	}
	res.push_back('x');
	res += (to_string(a));
	res.push_back('y');
	res += to_string(b);
	res.push_back('z');
	res += to_string(c);
	return res;
}

double TPolinom::Calculate(int _x, int _y, int _z) const
{
	double res=0;
	TMonom work;
	register int a, b, c, index, consta;
	for (register int i = 1; i < self.GetLen(); i++)
	{
		work = self.GetVal(i);
		index = work.GetIndex();
		consta = work.GetConsta();
		{
			a = (int)(index / 100);
			b = (int)((index - a * 100) / 10);
			c = index - a * 100 - b * 10;
		}
		res += consta*(powl(_x,a)*powl(_y,b)*powl(_z,c));
	}
	return res;
};

//end of user methods;

ostream & operator<<(ostream &out, const TPolinom &_enter)
{
	for (register int i = 1; i < _enter.GetLen(); i++)
		out << _enter.ToString(i) <<' ';
	return out;
}
