在主框架的InitInstance()函数开头添加以下代码：
CCommandLineInfo cmdInfo;
ParseCommandLine(cmdInfo);
CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);

在主框架的OnCreate()函数(WM_CREATE)开头添加以下代码：
//启动画面代码
CenterWindow();  
CSplashWnd::ShowSplashScreen(this);  

//  this->MoveWindow(0,0,0,0);    
//  this->SetTimer(1,2000,NULL);//注意这个2000一点要等于步骤1中的2000 
Sleep(1000);//使得画面停止约1s后启动主画面，<span style="color:#ff0000;">
	///貌似可以用定时器，希望大虾指教</span>。
	//1000 要与SetTimer中1000 同步，使画面链接流畅  



在工程中添加bitmap资源（启动画面图片），将其ID置为IDB_SPLASH