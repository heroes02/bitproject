#pragma once
#ifndef AUTODRIVEMODE_H
#define AUTODRIVEMODE_H

#include "Mode.h"

class AutoDriveMode : public OperatingMode {
public:
	explicit AutoDriveMode(MainMachine* const);
	~AutoDriveMode() override;
	mode run() override;

private:  //���� ��� ������

};

#endif