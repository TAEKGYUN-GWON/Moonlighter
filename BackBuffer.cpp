#include "stdafx.h"
#include "BackBuffer.h"

void BackBuffer::init()
{
	HDC hdc = GetDC(_hWnd);

	hMemDC = CreateCompatibleDC(hdc);	// 빈 DC영역 하나를 만든다
	hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);
}