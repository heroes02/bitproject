#include "AutoDriveMode.h"

/////////////////////////////////////////////////////////////////////////////
//public
AutoDriveMode::AutoDriveMode(MainMachine* const mainMachine)
	:OperatingMode(mainMachine, "AutoDrive")
{

}

AutoDriveMode::~AutoDriveMode() {}

//======================================================================
mode AutoDriveMode::run() { // ���� ������ ��� �̸��� ����
	DebugMsg("run ����");
	/* ���⿡ ��ü���� ������ �ۼ� */ 
	return mode::ManualDrive;
}
//======================================================================

/////////////////////////////////////////////////////////////////////////////
//private