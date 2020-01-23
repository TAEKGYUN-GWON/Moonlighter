#include "stdafx.h"
#include "BackBuffer.h"

void BackBuffer::init()
{
	HDC hdc = GetDC(_hWnd);

	hMemDC = CreateCompatibleDC(hdc);	// �� DC���� �ϳ��� �����
	hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);
}