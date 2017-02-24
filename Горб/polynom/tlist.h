#ifndef __TLIST_H__
#define __TLIST_H__

#include <stdlib.h>
#include <stdio.h>

#define CH_STR 10

// start clacc TList
template <class type>
class TList
{
private:
	struct TNode
	{
		type val;
		TNode *pNext;
		TNode *pPrev;
		short int pos;
	};
	TNode *pFirst;
	TNode *pCurr;
	short int len;
	void RePos(bool key);
	void FullRePos();
	
public:
	TList();
	~TList();
	short int GetLen() const;
	short int GetPos() { return pos; };
	void SetPos(int _pos);
	void GoNext();
	void GoBack();
	void InsFirst(const type _val);
	void InsLast(const type _val);
	void Ins(int _pos, const type _val);
	void DelFirst();
	void DelLast();
	void SetVal(const int _pos,const type _val);
	type GetVal(const int _pos);
	void DelCell(int _pos);
	void Delete();
};

template <class type>
TList<type>::TList()
{
	pCurr = pFirst = nullptr;
	len = 0;
};

template <class type>
TList<type>::~TList()
{
	if (pFirst == nullptr)
	{
		delete pFirst;
		delete pCurr;
	}
	else if (len == 1)
	{
		delete pFirst;
	}
	else
	{
		SetPos(1);
		delete pFirst;
		TNode *prev;
		while (pCurr->pos != len - 1)
		{
			prev=pCurr;
			GoNext();
			delete prev;
		}
		delete pCurr;
	}
};

template <class type>
short int TList<type>::GetLen() const
{ 
	return len;
};

template <class type>
void TList<type>::InsFirst(const type _val)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode;
		pFirst->pos = 0;
		pFirst->val = _val;
		pFirst->pNext = pFirst->pPrev = nullptr;
		++len;
		return;
	} 
	TNode *p = new TNode;
	if (p == 0) throw ("Bad mem alloc on create");
	TNode *prev = pFirst;
	p->val = _val;
	p->pNext = pFirst;
	p->pPrev = nullptr;
	pCurr = pFirst = p;
	TNode *next = pFirst->pNext;
	next->pPrev = pFirst;
	++len;
	FullRePos();
};

template <class type>
void TList<type>::InsLast(const type _val)
{
	if (pFirst == nullptr)
	{	
		InsFirst(_val);
		return;
	} 
		SetPos(len-1);
	TNode *p = new TNode;
	p->val = _val;
	p->pos = len;
	p->pNext = nullptr;
	++len;
	pCurr->pNext = p;
	p->pPrev = pCurr;
};

template<class type>
inline void TList<type>::SetPos(int _pos)
{
	if (_pos<0 || _pos>len) throw ("Invalid position: out of the range");
	if (_pos == 0)
	{
		pCurr = pFirst;
		return;
	}
	while (pCurr->pos < _pos) GoNext();
	while (pCurr->pos > _pos) GoBack();

};

template<class type>
inline void TList<type>::GoNext()
{
	if (pCurr->pNext == nullptr)
	{
		//throw ("End of List!");
		return;
	}
		pCurr = pCurr->pNext;
};

template <class type>
inline void TList<type>::GoBack()
{
	if (pCurr->pPrev == nullptr)
	{
		//throw ("Out of first of the List!");
		return;
	}
	pCurr = pCurr->pPrev;
};

template <class type>
void TList<type>::Ins(int _pos, const type _val)
{
	if (_pos < 0 || _pos > len) throw ("Bad position: out of the range!");
	if (pFirst == nullptr) InsFirst(_val);
	else if (_pos == 0) InsFirst(_val);
	else if (_pos == len) InsLast(_val);
	else
	{
		SetPos(_pos);
		TNode *p = new TNode;
		TNode *prev = pCurr->pPrev;
		p->pos = _pos;
		p->val = _val;
		pCurr->pPrev = p;
		prev->pNext = p;
		p->pNext = pCurr;
		p->pPrev = prev;
		RePos(1);
		++len;
	}
};

template <class type>
inline void TList<type>::RePos(bool key) //Only after Insert by Pos
{

	short int tmp = pCurr->pos; //
	while (pCurr->pos != len) //Re Position
	{
		if(key)	pCurr->pos++;
		else pCurr->pos--;
		GoNext();
	}
	//Back to list:
	SetPos(tmp);
}

template<class type>
inline void TList<type>::FullRePos() //Full RePos for all list from 0 -> len-1
{
	register short int ind = 0;
	pCurr = pFirst;
	while (ind!=len)
	{
		pCurr->pos = ind++;
		GoNext();
	}
};

template <class type>
inline void TList<type>::DelFirst()
{
	if (pFirst == nullptr) return;
	TNode *p = pFirst->pNext;
	delete pFirst;
	--len;
	p->pPrev = nullptr;
	pCurr = pFirst = p;
	FullRePos();
};

template <class type>
inline void TList<type>::DelLast()
{
	if (pFirst == nullptr) return;
	SetPos(len-1);
	TNode *p = pCurr->pPrev;
	p->pNext = nullptr;
	delete pCurr;
	pCurr = p;
	--len;
};

template<class type>
inline void TList<type>::SetVal(const int _pos, const type _val)
{
	if (_pos<0 || _pos>len) throw ("Bad position: out of the range");
	SetPos(_pos);
	pCurr->val = _val;
};

template<class type>
inline type TList<type>::GetVal(const int _pos)
{
	if (_pos<0 || _pos>len) throw ("Bad position: out of the range");
	SetPos(_pos);
	return pCurr->val;
};

template<class type>
void TList<type>::DelCell(const int _pos)
{
	if (_pos<0 || _pos>len) throw ("Bad position: out of the range");
	if (pFirst == nullptr) return;
	else if (_pos == 0) DelFirst();
	else if (_pos == len) DelLast();
	else
	{
		SetPos(_pos);
		TNode *prev = pCurr->pPrev;
		TNode *next = pCurr->pNext;
		delete pCurr;
		prev->pNext = next;
		next->pPrev = prev;
		--len;
		FullRePos();
	}
}

template<class type>
inline void TList<type>::Delete()
{
	::TList<type>::~TList();
	pFirst = pCurr = nullptr;
	len = 0;
};

#endif
