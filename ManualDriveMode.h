#pragma once
#ifndef MANUALDRIVEMODE_H
#define MANUALDRIVEMODE_H

#include "Mode.h"

class ManualDriveMode : public OperatingMode {
public:
	explicit ManualDriveMode(MainMachine* const);
	~ManualDriveMode() override;
	mode run() override;

private:  //���� ��� ������
	
};

#endif