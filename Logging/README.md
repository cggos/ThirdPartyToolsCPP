# Log Management & Configuration

---

* [MFC下的日志系统开发](http://blog.csdn.net/vector03/article/details/6419199)

## [log4cplus](https://sourceforge.net/projects/log4cplus/)
log4cplus is a simple to use C++ logging API providing thread-safe, flexible, and arbitrarily granular control over log management and configuration. It is modelled after the Java log4j API.  
* [Microsoft Visual Studio 2010下log4cplus的安装，集成，测试](http://blog.csdn.net/eclipser1987/article/details/6904301)
* [log4cplus使用方法配置](https://my.oschina.net/lovecxx/blog/185951)
* **Sample Code**  
```
  #include <log4cplus/loggingmacros.h>
  #include <log4cplus/logger.h>
  #include <log4cplus/consoleappender.h>
  #include <log4cplus/layout.h>
  #include<log4cplus/fileappender.h>

  #include <iomanip>

  using namespace log4cplus;
  using namespace log4cplus::helpers;

  int main()
  {
      /* step 1: Instantiate an appender object */
      SharedObjectPtr<Appender> _append (new FileAppender("app.log"));//new FileAppender("app.log") new ConsoleAppender()
      _append->setName("append for test");

      /* step 2: Instantiate a layout object */
      std::string pattern = "%D{%Y/%m/%d  %H:%M:%S}  - %m [%l]%n";
      std::auto_ptr<Layout> _layout(new PatternLayout(pattern));

      /* step 3: Attach the layout object to the appender */
      _append->setLayout( _layout );

      /* step 4:  Instantiate a logger object */
      Logger _logger = Logger::getInstance("test");

      /* step 5: Attach the appender object to the  logger  */
      _logger.addAppender(_append);

      /* step 6: Set a priority for the logger  */
      _logger.setLogLevel(ALL_LOG_LEVEL);

      /*logactivity*/
      LOG4CPLUS_TRACE(_logger, "This is " << "just a t" << "est.");
      LOG4CPLUS_DEBUG(_logger, "This is a bool:" << true);
      LOG4CPLUS_INFO (_logger, "This is a char:" << 'x');
      LOG4CPLUS_WARN (_logger, "This is a int:" << 1000);
      LOG4CPLUS_ERROR(_logger, "This is a long(hex):" << std::hex << 100000000);
      LOG4CPLUS_FATAL(_logger, "This is a double:" << std::setprecision(7) << 1.023456789);

      getchar();

      return 0;
  }
```
