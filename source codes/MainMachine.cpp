#include "MainMachine.h"
#include "AutoDriveMode.h"
#include "ManualDriveMode.h"
#include "TakePhotoMode.h"
#include "ImageProcessMode.h"
#include "Logger.h"

#include <iostream>  // ������
#include <stdexcept>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//public
MainMachine::MainMachine() 
	: currentMode(mode::AutoDrive), //�ʱ� ���
	  logger(new Logger(this, "MainMachine"))
{
	try {
		Operation[mode::AutoDrive] = new AutoDriveMode(this);
		Operation[mode::ManualDrive] = new ManualDriveMode(this);
		Operation[mode::TakePhoto] = new TakePhotoMode(this);
		Operation[mode::ImageProcess] = new ImageProcessMode(this);
	}
	catch (exception& e) { // ���� ó��
		cout << e.what() << endl;
		throw false; // ���� ���� ����
	}
}

MainMachine::~MainMachine() {
	for (auto& ModePairs : Operation) { // Operation�� �Ҵ��� �޸� ��� ����
		delete ModePairs.second;
	}
	delete logger;
}

//============================================================================
void MainMachine::StartMainLoop() {
	while (currentMode != mode::Quit){
		mode nextMode = Operation[currentMode]->run();
		currentMode = nextMode;
	}
}
//============================================================================

/////////////////////////////////////////////////////////////////////////////
//private



