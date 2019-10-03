#include "TakePhotoMode.h"

/////////////////////////////////////////////////////////////////////////////
//public
TakePhotoMode::TakePhotoMode(MainMachine* const mainMachine)
	:OperatingMode(mainMachine, "TakePhoto")
{

}

TakePhotoMode::~TakePhotoMode() {}

//======================================================================
mode TakePhotoMode::run() { // ���� ������ ��� �̸��� ����
	DebugMsg("run ����");
	/* ���⿡ ��ü���� ������ �ۼ� */
	return mode::ImageProcess;  
}
//======================================================================

/////////////////////////////////////////////////////////////////////////////
//private