#ifndef __TLIST_H__
#define __TLIST_H__


// struct
template <type>
struct TNode
{
	type value;
	TNode *pFirst;
	TNode *pPrev;
};

// start clacc TList
template <class type>
class TList
{
private:
	TNode *pFirst;
	short int count;
public:
	//-----iter-------//
	class iterator
	{
	private: //none
	public:
		iterator(TNode *p) { iter_p(p); } //BIG question. Really work??
		bool operator==(const iterator &ins) const
		{
			if (this = &ins) return true;
			return (iter_p == ins.iter_p);
		}
		bool operator!=(const iterator &ins) const
		{
			return !operator==(ins);
		}
		void operator++()
		{
			if (iter_p)
			{
				iter_p = iter_p->pNext;
			}
			else throw ('Stop: End of list');
		}
		void operator--()
		{
			if (iter_p)
			{
				iter_p = iter_p->pPrev;
			}
		}
	};
	//-----iter-------//
};

template <class type>
TList<type>::TList()
{
	pFirst(nullptr);
	pLast(nullptr);
	count(0);
};

template <class type>
void TList<type>::InsFirst(const type &_value)
{
	TNode *p = new TNode;   /* watch down */		
	p->value = _value;     /* attention -> class _value must have override of = */
	if(pFirst == nullptr) /*  watch up  */
	{
		p->pNext = p->pPrev = nullptr;
	}
	else
	{
		pPrev = nullptr;
		p->pLast = nullptr;
		p->pNext = pFirst;
		pFirst = p;
	}
	count++;
};

template <class type>
void TList<type>::InsLast(const type &_value)
{
	TNode *p = new TNode;   /* watch down */
	p->value = _value;     /* attention -> class _value must have override of = */
	p-> pNext = nullptr;
	p->pPrev = pLast;
	pLast = p;
	if (pFirst == nullptr) pFirst = p;
	count++;
};

template <class type>
void TList<type>::DelFirst()
{
	if (pFirst == nullptr) return;
	TNode *p = pFirst->pNext;
	delete pFirst;
	count--;
	pFirst = p; //not ended
};


template <class type>
void TList<type>::DelLast()
{
	if (pFirst == nullptr) return;
	//
	pLast = pPrev = nullptr; //not ended
};



#endif
