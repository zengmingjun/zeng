#include "framework.h"
#include "3dMieta-4.h"
#include "FWIND.h"


//void string2tchar(std::string& src, TCHAR* buf)
//{
//#ifdef UNICODE  
//    _stprintf_s(buf, MAX_PATH, _T("%S"), src.c_str());//%S宽字符  
//#else  
//    _stprintf_s(buf, MAX_PATH, _T("%s"), src.c_str());//%s单字符
//#endif
//}


ATOM bjCDQRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = bjCDQProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY3DMIETA4));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY3DMIETA4);
    wcex.lpszClassName = sbjCDQWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}



LRESULT CALLBACK    bjCDQProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  
   
    static int zt;
    static string str;
    
    static RECT rect;
    //GetClientRect(rectDlg);
     ifstream cd;
    
    static HWND hcd[100];
    switch (message)
    {
    case WM_CREATE:
    {
        string tme;
        cd.open("CDXinXi.txt");
        int bjcs = Qjcs;

        GetWindowRect(hWnd, &rect);

        while ((Qjcs- bjcs)*22<= rect.bottom-rect.top-60&& getline(cd, tme))
        {
            
            TCHAR ttme[MAX_PATH];
            _stprintf_s(ttme, MAX_PATH, _T("%S"), tme.c_str());
            hcd[Qjcs - bjcs + 1]= CreateWindow(TEXT("BUTTON"), ttme, WS_VISIBLE | WS_CHILD, 0, (Qjcs - bjcs) * 22, 50, 20, hWnd, NULL, hInst, NULL);
            bjcs--;
        }
       
        
        cd.close();
      
    }
    break;
    case WM_COMMAND:
        int wmId;
        wmId = LOWORD(wParam);
        // 分析菜单选择:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
       
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 在此处添加使用 hdc 的任何绘图代码...
       /* SendMessage(hWnd, DS_SETFONT, (WPARAM)mainhfont, NULL);*/
        HFONT ofont;
        ofont = (HFONT)SelectObject(hdc, mainhfont);

      /*  ifstream cd("CDXinXi.txt");
        string lx;
        TCHAR tlx[30];*/
      /*  WinExec("notepad.exe Numbers.txt", SW_SHOW);*/

      /*  int lxint = atoi(lx.c_str());*/

        
    
       /* cd.close();*/

       /* if (zt==1)
        {
            TCHAR tstr[30];
            _stprintf_s(tstr, 30, _T("%S"), str.c_str());
            TextOut(hdc, 0, 0, tstr, 30);
        }*/

        SelectObject(hdc, ofont),
            //DeleteObject(ofont);
            EndPaint(hWnd, &ps);
    }
    break;
    case WM_LBUTTONDOWN:
        int windx, windy;
      
        windx = LOWORD(lParam);
        windy = HIWORD(lParam);
        
        break;
    case WM_CLOSE:
        DestroyWindow(hWnd);
        /*DeleteObject(hWnd);*/
        ShowWindow(QjMHwnd, SW_SHOW);
       /* InvalidateRect(QjMHwnd, NULL, TRUE);*/
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
