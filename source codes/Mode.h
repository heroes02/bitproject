#pragma once
#ifndef MODE_H
#define MODE_H

#include <string>
using namespace std;

class MainMachine;
class Logger;

enum class mode {  // ��� �̸�
	AutoDrive, ManualDrive, TakePhoto, ImageProcess, Quit  // �ʿ信 ���� �߰�/����
};
//===============================================================================

class OperatingMode {  // �߻�Ŭ����
public:
	OperatingMode(MainMachine* const, const string);
	virtual ~OperatingMode();
	virtual mode run() = 0;  // ������ �ʼ�, �������� ������ ��� �̸��� ��ȯ

protected:
	MainMachine* const mainMachine;
	const string modeName;

protected:
	void DebugMsg(string);

private:
	Logger* const logger;  // ������ �ΰ�
};

#endif

