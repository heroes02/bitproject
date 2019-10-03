#include "ManualDriveMode.h"

/////////////////////////////////////////////////////////////////////////////
//public
ManualDriveMode::ManualDriveMode(MainMachine* const mainMachine) 
	:OperatingMode(mainMachine, "ManualDrive")
{

}

ManualDriveMode::~ManualDriveMode() {}

//======================================================================
mode ManualDriveMode::run() { // ���� ������ ��� �̸��� ����
	DebugMsg("run ����");
	/* ���⿡ ��ü���� ������ �ۼ� */
	return mode::TakePhoto; 
}
//======================================================================

/////////////////////////////////////////////////////////////////////////////
//private