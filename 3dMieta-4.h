#pragma once

#include "resource.h"






//char* Getcdpath();


ATOM                CDQRegisterClass(HINSTANCE hInstance);
ATOM                bjCDQRegisterClass(HINSTANCE hInstance);

LRESULT CALLBACK    CDQProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK    bjCDQProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	
