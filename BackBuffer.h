#pragma once
#include "singletonBase.h"
class BackBuffer : public singletonBase<BackBuffer>
{
private:
	DWORD resID;
	HDC hMemDC;
	HBITMAP hBit;
	HBITMAP hOBit;

public:
	virtual void init();
	HDC GetMemDC() { return hMemDC; }

};

