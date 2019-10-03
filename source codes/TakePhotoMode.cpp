#include "TakePhotoMode.h"
#include "Logger.h"

/////////////////////////////////////////////////////////////////////////////
//public
TakePhotoMode::TakePhotoMode(MainMachine* const mainMachine)
	:OperatingMode(mainMachine, "TakePhoto")
{

}

TakePhotoMode::~TakePhotoMode() {}

//======================================================================
mode TakePhotoMode::run() { // ���� ������ ��� �̸��� ����
	logger->DebugMsg("run ����");
	/* ���⿡ ��ü���� ������ �ۼ� */
	return mode::ImageProcess;  
}
//======================================================================

/////////////////////////////////////////////////////////////////////////////
//private