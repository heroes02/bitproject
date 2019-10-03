#pragma once
#ifndef MAINMACHINE_H
#define MAINMACHINE_H

#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

enum class mode;
class OperatingMode;
class Logger;

class MainMachine {
public:
	MainMachine();
	~MainMachine();
	void StartMainLoop();

private:
	mode currentMode;
	unordered_map<mode, OperatingMode*> Operation;
	Logger* const logger;  // ������ �ΰ�

	void DebugMsg(string msg);

	// �� �� ��尣 �����ؾ��ϴ� �ڿ���(ex> å�� ����, å ����, etc)
};
#endif
