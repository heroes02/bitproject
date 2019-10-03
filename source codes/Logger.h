#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
using namespace std;

class MainMachine;

class Logger {
public:
	Logger(MainMachine* const mainMachine, const string moduleName);
	~Logger();

	// DB�� ����ϱ�(DBComunication�� ���)
	// ���Ͽ� ���
	// UI�� ��� �޽��� �ۼ� 
	// etc

	template<typename... T>
	void DebugMsg(T&&... args) const {
#ifndef NDEBUG
		cout << "[Debug] From: [" << moduleName << "], Message: ";
		(cout << ... << args) << endl; //C++17 ���, Folding Expression
#else
		// Do Nothing on Release Build!
#endif
	}

private:
	MainMachine* const mainMachine;
	const string moduleName;
};
#endif