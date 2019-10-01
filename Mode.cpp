#include "Mode.h"
#include "MainMachine.h"
#include "Logger.h"

OperatingMode::OperatingMode(MainMachine* const mainMachine, const string modeName)
	: mainMachine(mainMachine), 
      modeName(modeName), 
	  logger(new Logger(modeName, mainMachine))
{	
	if (this->mainMachine == nullptr) throw logic_error("Error: mainMachine�� nullptr �Դϴ�.");
	if (this->logger == nullptr) throw logic_error("Error: logger�� nullptr �Դϴ�.");
}

void OperatingMode::DebugMsg(string msg) { logger->Log(msg); }

OperatingMode::~OperatingMode() {
	delete logger;
}