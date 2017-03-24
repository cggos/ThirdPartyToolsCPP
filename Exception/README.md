# CExceptionOpt

## ShowErrorMsg (GetLastError)
* 使用实例：   
```
if(!GetProcessId(NULL))
	CExceptionOpt::ShowErrorMsg(TEXT("GetProcessId"));
```

## 生产Dump文件（使用WinDbg分析）
* 使用实例：   
在程序入口加入生成dump文件功能 ，如下：  
```
SetUnhandledExceptionFilter(CExceptionOpt::ExceptionFilter);
```
**Related: **[Catch All Bugs with BugTrap](https://www.codeproject.com/kb/applications/bugtrap.aspx)