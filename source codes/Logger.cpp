#include "Logger.h"
#include "MainMachine.h"
#include <iostream>
using namespace std;

Logger::Logger(string modeName, MainMachine* const mainMachine)
	: modeName(modeName), mainMachine(mainMachine)
{}

Logger::~Logger() {}

void Logger::Log(string msg) {
	string debugMsg = "Mode Name: [" + modeName + "], Message: " + msg + "\n";
	cout << debugMsg; //�ܼ� ���
	/* ���Ͽ� ���, UI�� ��� etc */
}