#include "ManualDriveMode.h"
#include "Logger.h"

/////////////////////////////////////////////////////////////////////////////
//public
ManualDriveMode::ManualDriveMode(MainMachine* const mainMachine) 
	:OperatingMode(mainMachine, "ManualDrive")
{

}

ManualDriveMode::~ManualDriveMode() {}

//======================================================================
mode ManualDriveMode::run() { // ���� ������ ��� �̸��� ����
	logger->DebugMsg("run ����");
	/* ���⿡ ��ü���� ������ �ۼ� */
	return mode::TakePhoto; 
}
//======================================================================

/////////////////////////////////////////////////////////////////////////////
//private