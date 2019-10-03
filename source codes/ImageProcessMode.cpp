#include "ImageProcessMode.h"
#include "Logger.h"

/////////////////////////////////////////////////////////////////////////////
//public
ImageProcessMode::ImageProcessMode(MainMachine* const mainMachine)
	:OperatingMode(mainMachine, "ImageProcess")
{}

ImageProcessMode::~ImageProcessMode() {}

//======================================================================
mode ImageProcessMode::run() { // ���� ������ ��� �̸��� ����
	logger->DebugMsg("run ����");
	/* ���⿡ ��ü���� ������ �ۼ� */
	return mode::Quit;  // ���� ���� ����
}
//======================================================================

/////////////////////////////////////////////////////////////////////////////
//private