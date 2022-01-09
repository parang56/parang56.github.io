/*
	Banking Project/ AccountArray.h Ver.01
	업데이트(2022,01,04)
	By: 둠치킨
*/

#ifndef __ACCOUN_ARRAY_H__
#define __ACCOUN_ARRAY_H__

#include "Account.h"

typedef Account * ACCOUNT_PTR;

class BoundCheckAccountPtrArray 
{
private:
	ACCOUNT_PTR * arr;
	int arrlen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) { }
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) { }

public:
	BoundCheckAccountPtrArray(int len=100);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};
#endif