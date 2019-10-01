#pragma once
#ifndef MAINMACHINE_H
#define MAINMACHINE_H

#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

enum class mode;
class OperatingMode;

class MainMachine {
public:
	MainMachine();
	~MainMachine();
	void StartMainLoop();

private:
	void SetMode(mode);

private:
	mode currentMode;
	unordered_map<mode, OperatingMode*> Operation;
	// �� �� ��尣 �����ؾ��ϴ� �ڿ���(ex> å�� ����, å ����, etc)
};
#endif
