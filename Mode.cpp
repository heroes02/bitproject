#include "Mode.h"
#include "MainMachine.h"
#include "Logger.h"

OperatingMode::OperatingMode(MainMachine* const mainMachine, const string modeName)
	: mainMachine(mainMachine), 
      modeName(modeName), 
	  logger(new Logger(modeName, mainMachine))
{	
	if (this->mainMachine == nullptr) { 
		string ErrorMsg = "Error: modeName[" + modeName + "], mainMachine�� nullptr �Դϴ�.";
		throw logic_error(ErrorMsg);
	}
	if (this->logger == nullptr) { 
		string ErrorMsg = "Error: modeName[" + modeName + "], logger�� nullptr �Դϴ�.";
		throw logic_error(ErrorMsg);
	}
}

void OperatingMode::DebugMsg(string msg) { logger->Log(msg); }

OperatingMode::~OperatingMode() {
	delete logger;
}