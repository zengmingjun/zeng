#include "framework.h"
#include "3dMieta-4.h"
#include "FWIND.h"




 int JmZt = 0;
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

ATOM CDQRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = CDQProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY3DMIETA4));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY3DMIETA4);
    wcex.lpszClassName = sCDQWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}



LRESULT CALLBACK    CDQProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    
    //公用对象
    static HWND dxname;
    static HWND QueRen, ShangYiBu;

    //
     static HWND hpoint, hline, hpace;
    //hpoint
     static HWND hPcoor;

    //hline
     static HWND hLcoor;

     //hpace
     static HWND hPEcoor,hDdian;
     //静态文本框
     static HWND nest, cost;
    
     //输入数据流
     ofstream sjf;

    switch (message)
    {
    case WM_CREATE:
    {
        if (JmZt==0)
        {
            hpoint = CreateWindow(TEXT("BUTTON"), TEXT("点类型"), WS_VISIBLE | WS_CHILD, 0, 0, 50, 20, hWnd, (HMENU)11, hInst, NULL);
            hline = CreateWindow(TEXT("BUTTON"), TEXT("线类型"), WS_VISIBLE | WS_CHILD, 60, 0, 50, 20, hWnd, (HMENU)12, hInst, NULL);
            hpace = CreateWindow(TEXT("BUTTON"), TEXT("面类型"), WS_VISIBLE | WS_CHILD, 120, 0, 50, 20, hWnd, (HMENU)13, hInst, NULL);

            SendMessage(hpoint, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(hline, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(hpace, WM_SETFONT, (WPARAM)mainhfont, NULL);

            UpdateWindow(hpoint);
            UpdateWindow(hline);
            UpdateWindow(hpace);
            InvalidateRect(hWnd, NULL, TRUE);//重绘窗体矩形

            break;
        }
        if (JmZt==11)
        {
            /*ShowWindow(hpoint, SW_HIDE);
            ShowWindow(hline,   SW_HIDE);
            ShowWindow(hpace,  SW_HIDE);*/
            DestroyWindow(hpoint);
            DestroyWindow(hline);
            DestroyWindow(hpace);
            dxname = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 0, 200, 20, hWnd, (HMENU)111, hInst, NULL);
            hPcoor= CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 25, 200, 20, hWnd, (HMENU)112, hInst, NULL);
            QueRen = CreateWindow(TEXT("BUTTON"), TEXT("确认"), WS_VISIBLE | WS_CHILD, 0, 100, 50, 30, hWnd, (HMENU)001, hInst, NULL);
            ShangYiBu = CreateWindow(TEXT("BUTTON"), TEXT("取消"), WS_VISIBLE | WS_CHILD, 100, 100, 50, 30, hWnd, (HMENU)002, hInst, NULL);
           /* nest = CreateWindow(TEXT("static"), TEXT("名"), WS_VISIBLE | WS_CHILD, 0, 0, 50, 30, hWnd, (HMENU)0101, hInst, NULL);
            cost = CreateWindow(TEXT("static"), TEXT("坐标"), WS_VISIBLE | WS_CHILD, 0, 25, 50, 30, hWnd, (HMENU)0101, hInst, NULL);*/

            SendMessage(dxname, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(hPcoor, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(QueRen, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(ShangYiBu, WM_SETFONT, (WPARAM)mainhfont, NULL);
            
          /*  SendMessage(nest, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(cost, WM_SETFONT, (WPARAM)mainhfont, NULL);*/
            //SendMessage(hWnd, WM_PAINT, NULL, NULL);
            UpdateWindow(hWnd);
            UpdateWindow(dxname);
            UpdateWindow(hPcoor);
            UpdateWindow(QueRen);
            UpdateWindow(ShangYiBu);
           /* SendMessage(hWnd, WM_PAINT, NULL, NULL);*/
            InvalidateRect(hWnd, NULL, TRUE);//重绘窗体矩形
            break;
        }   
        if (JmZt == 12)
        {



            DestroyWindow(hpoint);
            DestroyWindow(hline);
            DestroyWindow(hpace);
            dxname = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 0, 200, 20, hWnd, (HMENU)111, hInst, NULL);
            hLcoor = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 25, 200, 20, hWnd, (HMENU)112, hInst, NULL);
            QueRen = CreateWindow(TEXT("BUTTON"), TEXT("确认"), WS_VISIBLE | WS_CHILD, 0, 100, 50, 30, hWnd, (HMENU)001, hInst, NULL);
            ShangYiBu = CreateWindow(TEXT("BUTTON"), TEXT("取消"), WS_VISIBLE | WS_CHILD, 100, 100, 50, 30, hWnd, (HMENU)002, hInst, NULL);
            /* nest = CreateWindow(TEXT("static"), TEXT("名"), WS_VISIBLE | WS_CHILD, 0, 0, 50, 30, hWnd, (HMENU)0101, hInst, NULL);
             cost = CreateWindow(TEXT("static"), TEXT("坐标"), WS_VISIBLE | WS_CHILD, 0, 25, 50, 30, hWnd, (HMENU)0101, hInst, NULL);*/

            SendMessage(dxname, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(hLcoor, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(QueRen, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(ShangYiBu, WM_SETFONT, (WPARAM)mainhfont, NULL);

            /*  SendMessage(nest, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(cost, WM_SETFONT, (WPARAM)mainhfont, NULL);*/
            //SendMessage(hWnd, WM_PAINT, NULL, NULL);
            UpdateWindow(hWnd);
            UpdateWindow(dxname);
            UpdateWindow(hLcoor);
            UpdateWindow(QueRen);
            UpdateWindow(ShangYiBu);
            InvalidateRect(hWnd, NULL, TRUE);//重绘窗体矩形
            break;
        }
        if (JmZt == 13)
        {
            DestroyWindow(hpoint);
            DestroyWindow(hline);
            DestroyWindow(hpace);
            dxname = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 0, 200, 20, hWnd, (HMENU)111, hInst, NULL);
            hDdian = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 25, 200, 20, hWnd, (HMENU)112, hInst, NULL);
            hPEcoor = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 50, 200, 20, hWnd, (HMENU)113, hInst, NULL);
            QueRen = CreateWindow(TEXT("BUTTON"), TEXT("确认"), WS_VISIBLE | WS_CHILD, 0, 100, 50, 30, hWnd, (HMENU)001, hInst, NULL);
            ShangYiBu = CreateWindow(TEXT("BUTTON"), TEXT("取消"), WS_VISIBLE | WS_CHILD, 100, 100, 50, 30, hWnd, (HMENU)002, hInst, NULL);
         
            SendMessage(dxname, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(hDdian, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(hPEcoor, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(QueRen, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(ShangYiBu, WM_SETFONT, (WPARAM)mainhfont, NULL);
            InvalidateRect(hWnd, NULL, TRUE);//重绘窗体矩形
            break;
        }
      
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
       
        case 11://点
            JmZt = 11;
            SendMessage(hWnd, WM_CREATE, NULL, NULL);
            /*InvalidateRect(hWnd,NULL,TRUE);*/
            break;
        case 12://线
            JmZt = 12;
            SendMessage(hWnd, WM_CREATE, NULL, NULL);
            /*InvalidateRect(hWnd, NULL, TRUE);*/
            break;
        case 13://面
            JmZt = 13;
            SendMessage(hWnd, WM_CREATE, NULL, NULL);
            /*InvalidateRect(hWnd, NULL, TRUE);*/
            break;
        case 001://确认
            

            if (JmZt==11)//点
            {
                TCHAR tdxname[MAX_PATH], thPcoor[MAX_PATH];
                GetWindowText(dxname, tdxname,size(tdxname));
                GetWindowText(hPcoor, thPcoor, size(thPcoor));
                char dxname_c[MAX_PATH*2], hPcoor_c[MAX_PATH*2];
                wcstombs(dxname_c, tdxname, MAX_PATH);
                wcstombs(hPcoor_c, thPcoor, MAX_PATH);
                ofstream fout(Cdpath, ios::app);

                fout << JmZt<< endl << dxname_c   << endl << hPcoor_c<< endl;

                fout.close();
           
                DestroyWindow(dxname);
                DestroyWindow(hPcoor);
                DestroyWindow(QueRen);
                DestroyWindow(ShangYiBu);
         
                JmZt =0;
            }
            if (JmZt==12)
            {
                TCHAR tdxname[MAX_PATH], thLcoor[MAX_PATH];
                GetWindowText(dxname, tdxname, size(tdxname));
                GetWindowText(hLcoor, thLcoor, size(thLcoor));
                char dxname_c[MAX_PATH * 2], hPcoor_c[MAX_PATH * 2];
                wcstombs(dxname_c, tdxname, MAX_PATH);
                wcstombs(hPcoor_c, thLcoor, MAX_PATH);
                ofstream fout(Cdpath, ios::app);

                fout << JmZt << endl << dxname_c << endl << hPcoor_c << endl;

                fout.close();
                
                DestroyWindow(dxname);
                DestroyWindow(hLcoor);
                DestroyWindow(QueRen);
                DestroyWindow(ShangYiBu);
             
                JmZt = 0;
            }
            if (JmZt==13)
            {

                TCHAR tdxname[MAX_PATH], thPEcoor[MAX_PATH],thDdian[MAX_PATH];
                GetWindowText(dxname, tdxname, size(tdxname));
                GetWindowText(hDdian, thDdian, size(thDdian));
                GetWindowText(hPEcoor, thPEcoor, size(thPEcoor));
                char dxname_c[MAX_PATH * 2], hPEcoor_c[MAX_PATH * 2], hDdian_c[MAX_PATH * 2];
                wcstombs(dxname_c, tdxname, MAX_PATH);
                wcstombs(hPEcoor_c, thPEcoor, MAX_PATH);
                wcstombs(hDdian_c, thDdian, MAX_PATH);
                ofstream fout(Cdpath, ios::app);

                fout << JmZt << endl << dxname_c<<endl<< hDdian_c << endl << hPEcoor_c << endl;

                fout.close();

                DestroyWindow(hDdian);
                DestroyWindow(dxname);
                DestroyWindow(hPEcoor);
                DestroyWindow(QueRen);
                DestroyWindow(ShangYiBu);
                JmZt = 0;
            }
            SendMessage(hWnd, WM_CREATE, NULL, NULL);
         /*   InvalidateRect(hWnd, NULL, TRUE);*/
            break;
        case 002://取消

            if (JmZt==11)
            {
                DestroyWindow(dxname);
                DestroyWindow(hPcoor);
                DestroyWindow(QueRen);
                DestroyWindow(ShangYiBu);
                JmZt = 0;
            }
            if ( JmZt == 12)
            {
                DestroyWindow(dxname);
                DestroyWindow(hLcoor);
                DestroyWindow(QueRen);
                DestroyWindow(ShangYiBu);
                JmZt = 0;
            }
            if (JmZt == 13)
            {
                DestroyWindow(dxname);
                DestroyWindow(hPEcoor);
                DestroyWindow(hDdian);
                DestroyWindow(QueRen);
                DestroyWindow(ShangYiBu);
                JmZt = 0;
            }
            
            SendMessage(hWnd, WM_CREATE, NULL, NULL);
         
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
    ofont= (HFONT)SelectObject(hdc, mainhfont);


    if (JmZt==11|| JmZt == 12)
    {
        TextOut(hdc, 0, 0, TEXT("端名"),2);
        TextOut(hdc, 0, 25, TEXT("坐标"), 2);
         
    }
    if (JmZt==13)
    {
        TextOut(hdc, 0, 0, TEXT("端名"), 2); 
        TextOut(hdc, 0, 25, TEXT("端数"), 2);
        TextOut(hdc, 0, 50, TEXT("坐标"), 2);
    }
    
    SelectObject(hdc,ofont),
    //DeleteObject(ofont);
    EndPaint(hWnd, &ps);
    }
    break;
    case WM_CLOSE:
        DestroyWindow(hWnd);
       /*DeleteObject(hWnd);*/
       ShowWindow(QjMHwnd, SW_SHOW);
       break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}



