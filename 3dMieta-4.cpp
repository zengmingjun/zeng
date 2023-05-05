// 3dMieta-4.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "3dMieta-4.h"

#define MAX_LOADSTRING 100





//HWND CDQq, MNQq, SZq;
// 全局变量:
// 
HINSTANCE hInst;
HWND	QjMHwnd;
int Qjcs;

                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];
WCHAR sCDQWindowClass[100] = TEXT("CDQ_WINDName");// 主窗口类名
WCHAR sbjCDQWindowClass[100] = TEXT("bjCDQ_WINDName");
char Cdpath[MAX_PATH]; //当前存档路径

HFONT mainhfont = CreateFont(15, 0, 0, 0, 200, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, 0, TEXT("黑体"));// 全局字体

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND , UINT , WPARAM , LPARAM );

//char* Getcdpath() {
//    return Cdpath;
//}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。
    //基础文件配置
 /*   if (_access("CDXinXi.txt", 00) == -1)
    {*/
      /*  ofstream cdf("CDXinXi.txt",ios::app);
        cdf.close();*/
   /* }*/
   
    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY3DMIETA4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY3DMIETA4));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY3DMIETA4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY3DMIETA4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   QjMHwnd = hWnd;
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   string tme;
   ifstream cdf("CDXinXi.txt");
   int cs = 0;
   while (getline(cdf, tme))
   {
       cs++;
   }
   Qjcs = cs;

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
static int a = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   static HWND CDQ, MNQ, SZ;
   //存档器子控件
   //-1
   static HWND CDbj, CDcj;

   //-2
   static HWND  CDcjEDIT;
   //模拟器子控件

   //设置子控件

   //上一步
   static HWND ShangYiBu;
   //确认
   static HWND QueRen;
   //-
   static TCHAR cdname[MAX_PATH];

   //确认001上一步002

   //静态文本
  
           switch (message)
    {
    case WM_CREATE:
     
        
        if (a == 0)
        {
            CDQ = CreateWindow(TEXT("BUTTON"), TEXT("存档器"), WS_VISIBLE | WS_CHILD, 0, 0, 50, 30, hWnd, (HMENU)11, hInst, NULL);
            MNQ = CreateWindow(TEXT("BUTTON"), TEXT("模拟器"), WS_VISIBLE | WS_CHILD, 60, 0, 50, 30, hWnd, (HMENU)12, hInst, NULL);
            SZ = CreateWindow(TEXT("BUTTON"), TEXT("设置"), WS_VISIBLE | WS_CHILD, 120, 0, 50, 30, hWnd, (HMENU)13, hInst, NULL);
           
            SendMessage(CDQ, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(MNQ, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(SZ, WM_SETFONT, (WPARAM)mainhfont, NULL);
           
            break;

        }
        if (a == 11)
        {
            /*DeleteObject(CDQq);
            DeleteObject(MNQq);
            DeleteObject(SZq);*/
            //存档器
            ShowWindow(CDQ, SW_HIDE);
            ShowWindow(MNQ, SW_HIDE);
            ShowWindow(SZ, SW_HIDE);
            CDcj = CreateWindow(TEXT("BUTTON"), TEXT("创建存档"), WS_VISIBLE | WS_CHILD, 0, 0, 100, 30, hWnd, (HMENU)111, hInst, NULL);
            CDbj = CreateWindow(TEXT("BUTTON"), TEXT("编辑存档"), WS_VISIBLE | WS_CHILD, 110, 0, 100, 30, hWnd, (HMENU)112, hInst, NULL);
            QueRen = CreateWindow(TEXT("BUTTON"), TEXT("确认"), WS_CHILD, 280, 200, 75, 30, hWnd, (HMENU)001, hInst, NULL);
            ShangYiBu = CreateWindow(TEXT("BUTTON"), TEXT("上一步"), WS_VISIBLE | WS_CHILD, 200, 200, 75, 30, hWnd, (HMENU)002, hInst, NULL);

            SendMessage(CDcj, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(CDbj, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(ShangYiBu, WM_SETFONT, (WPARAM)mainhfont, NULL);
            SendMessage(QueRen, WM_SETFONT, (WPARAM)mainhfont, NULL);
          


            /*CDQ = CreateWindow(TEXT("BUTTON"), TEXT("存档器"), WS_VISIBLE | WS_CHILD, 0, 0, 50, 30, hWnd, (HMENU)1, hInst, NULL);*/
          /*  PostQuitMessage(0);*/
            break;
        }
        if (a == 12)
        {
            //模拟器
            ShowWindow(CDQ, SW_HIDE);
            ShowWindow(MNQ, SW_HIDE);
            ShowWindow(SZ, SW_HIDE);
            break;
        }
        if (a == 13)
        {
            //设置
            ShowWindow(CDQ, SW_HIDE);
            ShowWindow(MNQ, SW_HIDE);
            ShowWindow(SZ, SW_HIDE);
            break;
        }
        if (a == 111)
        {
            //创建存档
            ShowWindow(CDcj, SW_HIDE);
            ShowWindow(CDbj, SW_HIDE);
            //
            ShowWindow(QueRen, SW_SHOW);
            CDcjEDIT = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 50, 0, 300, 20, hWnd, (HMENU)1111, hInst, NULL);
           
            break;
        }
        if (a == 112)
        {
            //编辑存档
            /*ShowWindow(CDcj, SW_HIDE);
            ShowWindow(CDbj, SW_HIDE);*/
          
            bjCDQRegisterClass(hInst);
            HWND bjCDQ;
            bjCDQ = CreateWindow(sbjCDQWindowClass, NULL, WS_OVERLAPPEDWINDOW, 200, 200, 300, 300, NULL, NULL, hInst, NULL);
            ShowWindow(bjCDQ, SW_SHOW);
            ShowWindow(hWnd, SW_HIDE);
                
            break;
        }
      
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case 11:
                a = 11;
                SendMessage(hWnd, WM_CREATE, NULL, NULL);
                break;
            case 12:
                a = 12;
                SendMessage(hWnd, WM_CREATE, NULL, NULL);
                break;
            case 13:
                a = 13;
                SendMessage(hWnd, WM_CREATE, NULL, NULL);
                break;
            case 111:
                //创建存档
                a = 111;
                SendMessage(hWnd, WM_CREATE, NULL, NULL);
                InvalidateRect(hWnd, NULL, TRUE);
              /*  SendMessage(hWnd, WM_PAINT, NULL, NULL);*/
                break;
            case 112:
                a = 112;
                SendMessage(hWnd, WM_CREATE, NULL, NULL);
                /*InvalidateRect(hWnd, NULL, TRUE);*/
                //编辑存档
                break;
            case 002:
                //上一步
                if (a==11)//存档器界面
                {
                    //显示
                    ShowWindow(CDQ, SW_RESTORE);
                    ShowWindow(MNQ, SW_RESTORE);
                    ShowWindow(SZ, SW_RESTORE);

                    //隐藏
                    ShowWindow(ShangYiBu, SW_HIDE);
                    ShowWindow(CDcj, SW_HIDE);
                    ShowWindow(CDbj, SW_HIDE);
                    a = 0;
                }
                if (a==111) //创建存档
                {
                   
                    ShowWindow(CDcj, SW_RESTORE);
                    ShowWindow(CDbj, SW_RESTORE);

                    ShowWindow(QueRen, SW_HIDE);
                    ShowWindow(CDcjEDIT, SW_HIDE);
                  //创建存档
                    a = 11;
                    /*ShowWindow(CDcj, SW_HIDE);*/
                  /*  InvalidateRect(hWnd, NULL, TRUE);*/
                }
                if (a == 112) //编辑存档
                {

                    ShowWindow(CDcj, SW_RESTORE);
                    ShowWindow(CDbj, SW_RESTORE);

                    ShowWindow(QueRen, SW_HIDE);
                    ShowWindow(CDcjEDIT, SW_HIDE);
                    //创建存档
                    a = 11;

               /*     InvalidateRect(hWnd, NULL, TRUE);*/
                    /*ShowWindow(CDcj, SW_HIDE);*/
                }
                
                if (a==12)//模拟器界面
                {

                }
                if (a==13)//设置界面
                {

                }
                break;
            case 001://确认
                if (a==111)
                {
                 
                 GetWindowText(CDcjEDIT,cdname, size(cdname));
                /* if (cdname != TEXT("") || cdname != TEXT(" ")|| cdname != NULL)
                 {*/
                     wsprintf(cdname, TEXT("%s.txt"), cdname);
                     fstream cdf;
                     cdf.open("CDXinXi.txt", ios::app|ios::in|ios::out);
                     char namechar_c[MAX_PATH];
                     
                     wcstombs(namechar_c, cdname, MAX_PATH);
                    /* if (_access(namechar_c, 0) != 0)
                     {*/
                          
                             cdf << namechar_c;
                             cdf << endl;

                             int cs=0;
                             string tme;
                             cdf.seekp(0);
                            
                             while (getline(cdf, tme))
                             {
                                 cs++;
                             }
                             Qjcs = cs;
                            
                             cdf.close();
                             wcstombs(Cdpath, cdname, MAX_PATH);

                             /*Cdpath = namechar_c;*/
                             ofstream cdbjf(cdname);

                             cdbjf.close();
                             SetWindowText(CDcjEDIT, TEXT(""));

                             HWND HCD;
                             CDQRegisterClass(hInst);
                             HCD = CreateWindow(sCDQWindowClass, NULL, WS_OVERLAPPEDWINDOW, 200, 200, 300, 300, hWnd, NULL, hInst, NULL);
                             ShowWindow(HCD, SW_SHOW);
                             ShowWindow(hWnd, SW_HIDE);
                         
                   /*  }*/
                /*     else
                     {
                         MessageBox(hWnd, TEXT("该存档已存在"), NULL, NULL);
                         SetWindowText(CDcjEDIT, TEXT(""));
                         cdf.close();
                     }*/
              /*   }
                 else
                 {
                     MessageBox(hWnd, TEXT("存档名不能为空"), NULL, NULL);

                 }*/
                }
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
           /* SendMessage(hWnd, DS_SETFONT, (WPARAM)mainhfont, NULL);*/
            HGDIOBJ Ofont = SelectObject(hdc, mainhfont);
            if (a==111)
            {

                TextOut(hdc,0,0,TEXT("存档名"),3);
            }
            
           
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        
        DeleteObject(mainhfont);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
