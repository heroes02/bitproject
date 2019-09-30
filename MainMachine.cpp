#include "MainMachine.h"
#include "AutoDriveMode.h"
#include "ManualDriveMode.h"
#include "TakePhotoMode.h"
#include "ImageProcessMode.h"

#include <iostream>  // ������
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//public
MainMachine::MainMachine() 
	: currentMode(mode::AutoDrive) //�ʱ� ���
{
	Operation[mode::AutoDrive] = new AutoDriveMode(this);
	Operation[mode::ManualDrive] = new ManualDriveMode(this);
	Operation[mode::TakePhoto] = new TakePhotoMode(this);
	Operation[mode::ImageProcess] = new ImageProcessMode(this);
}

MainMachine::~MainMachine() {
	for (auto& ModePairs : Operation) { // Operation�� �Ҵ��� �޸� ��� ����
		delete ModePairs.second;
	}
}

void MainMachine::SetDebugMsg(string msg) { logBuffer << msg; }

//============================================================================
void MainMachine::StartMainLoop() {
	while (currentMode != mode::Quit){
		mode nextMode = Operation[currentMode]->run();
		ShowDebugMsg();
		SetMode(nextMode);
	}
}
//============================================================================

/////////////////////////////////////////////////////////////////////////////
//private
void MainMachine::SetMode(mode nextMode) { currentMode = nextMode; }

void MainMachine::ShowDebugMsg() {
	cout << logBuffer.str();
	logBuffer.str("");  // ���� �ʱ�ȭ
}

