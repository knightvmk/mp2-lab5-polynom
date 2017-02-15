#ifndef __TLIST_H__
#define __TLIST_H__


// struct
template <type>
struct TNode
{
	type val;
	TNode *pNext;
	TNode *pPrev;
};

// start clacc TList
template <class type>
class TList
{
private:
	TNode *pFirst;
	TNode *pLast;
	short int len;
	short int pos;
public:
	TList();
	TList(int _len);
	void GetLen() { return len; };
	void GetPos() { return pos; };
	void SetPos(int _pos);
	void GoNext();
	void GoBack();
	void InsFirst(const type &_val);
	void InsLast(const type &_val);
	void Ins(int _pos, const type &_val);
	void DelFirst();
	void DelLast();
	void SetVal(const int _pos,const type _val);
	type GetVal(const int _pos);
	void DelCell(int _pos);
};

template <class type>
TList<type>::TList()
{
	pFirst = new TNode;
	pLast = new TNode;
	pLast = pFirst;
	pFirst->pPrev = pFirst->pNext = pFirst;
	count(1);
	pos = 0;
}

template<class type>
TList<type>::TList(int _len)
{
	pFirst = new TNode;
	pLast = new TNode;
	pLast->pNext = pFirst;
	while (len!=_len)
		do
		{
			//
		}
};

template <class type>
void TList<type>::InsFirst(const type &_val)
{
	SetPos(0);
	TNode *p = new TNode;
	//if (pFirst == nullptr) p = pFirst = pLast;
	p = pFirst;
	pFirst->pNext = p;
	//pFirst->pPrev = pLast;
	p->pPrev = pFirst;
	pFirst->val = _val;
	len++;
};

template <class type>
void TList<type>::InsLast(const type &_val)
{
	
	SetPos(len - 1);
	TNode *p = new TNode;
	//if (pFirst == nullptr) p = pFirst = pLast;
	p = pLast;
	pLast->pPrev = p;
	p->pNext = pLast;
	pLast->val = _val;
	len++;
};

template<class type>
void TList<type>::SetPos(int _pos)
{
	while (pos < _pos) GoNext();
	while (pos > _pos) GoBack();
	else return;
	if(pos!=_pos) throw ('HALT, not work method!')
};

template<class type>
void TList<type>::GoNext()
{
	/**p = new TNode;
	p = */pFirst=pFirst->pNext;
	if (pos + 1 == len) pos = 0;
	else ++pos;
	//delete p;
};

template <class type>
void TList<type>::GoBack()
{
	/**p = new TNode;
	p=*/pFirst=pFirst->pPrev;
	if (pos - 1 < 0) pos = len - 1;
	else --pos;
	//delete p;
};

template <class type>
void TList<type>::Ins(int _pos, const type &_val)
{
	if (_pos == 0)
	{ 
		InsFirst(_val); 
		return; 
	}
	if (_pos == len - 1)
	{
		InsLast(_val);
		return;
	}
	SetPos(_pos);
	TNode *p = new TNode;
	p->pNext = pFirst;
	pFirst->pPrev = p;
	GoBack();
	p->pPrev = pFirst;
	pFirst->pNext = p;
	p->val = _val;
	len++;
};

template <class type>
void TList<type>::DelFirst()
{
	if (pFirst == nullptr) return;
	TNode *p = new TNode;
	p = pFirst -> pNext;
	delete pFirst;
	pFirst = p;
	--len;
	SetPos(len - 1);
};


template <class type>
void TList<type>::DelLast()
{
	if (pLast == nullptr) return;
	TNode *p = new TNode;
	p = pLast -> pPrev;
	delete pLast;
	pLast = p;
	len--;
	SetPos(len - 1);
};

template<class type>
void TList<type>::SetVal(const int _pos, const type _val)
{
	SetPos(_pos);
	pFirst->val = _val;
};

template<class type>
type TList<type>::GetVal(const int _pos)
{
	SetPos(_pos);
	return pFirst->val;
};

template<class type>
void TList<type>::DelCell(const int _pos)
{
	if (_pos == 0)
	{
		DelFirst(_val);
		return;
	}
	if (_pos == len - 1)
	{
		DelLast(_val);
		return;
	}
	SetPos(_pos);
	TNode *prev = new TNode;
	TNode *next = new TNode;
	prev = pFirst->pPrev;
	prev->pNext = pFirst->pNext;
	next = pFirst->pNext;
	next->pPrev = prev;
	delete pFirst;
	len--;	
};

#endif
