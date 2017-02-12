// GenericService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

int function()
{
	TIMED_FUNC(timerObj);

	for (int i = 0; i < 10; i++){
		//TIMED_SCOPE(timerBlkObj, "heavy-iter");
		Sleep(1000);
	}


	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//// Load configuration from file
	//el::Configurations conf("C:\\tmp\\easy.conf");
	//// Reconfigure single logger
	//el::Loggers::reconfigureLogger("default", conf);
	//// Actually reconfigure all loggers instead
	//el::Loggers::reconfigureAllLoggers(conf);
	//// Now all the loggers will use configuration from file

	el::Configurations defaultConf;
	defaultConf.setToDefault();

	defaultConf.setGlobally(el::ConfigurationType::Filename, "C:\\tmp\\my.log");
	defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime{%d-%b-%Y %H:%m:%s:%g} [%level] %fbase %func: %msg");
	defaultConf.setGlobally(el::ConfigurationType::PerformanceTracking, "true");
	el::Loggers::reconfigureLogger("default", defaultConf);

	LOG(DEBUG) << "Using file configuration";
	function();

	return 0;
}


