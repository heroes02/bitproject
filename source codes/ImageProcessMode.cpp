#include "ImageProcessMode.h"

/////////////////////////////////////////////////////////////////////////////
//public
ImageProcessMode::ImageProcessMode(MainMachine* const mainMachine)
	:OperatingMode(mainMachine, "ImageProcess")
{

}

ImageProcessMode::~ImageProcessMode() {}

//======================================================================
mode ImageProcessMode::run() { // ���� ������ ��� �̸��� ����
	DebugMsg("run ����");
	/* ���⿡ ��ü���� ������ �ۼ� */
	return mode::Quit;  // ���� ���� ����
}
//======================================================================

/////////////////////////////////////////////////////////////////////////////
//private