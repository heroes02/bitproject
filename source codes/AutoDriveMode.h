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
	// 1. ī�޶󿡼� ������ ���� �� ����� ����(HardwareControl�� ��� �̿�)�ϴ� ���
	// 2. ����� ������ ���� ��ũ�� �ִ��� Ȯ���ϴ� ���
	// 3. ���� ��ũ���� ���� ��ġ������ �о�� ���(QRCODE, OCR etc)
	// 4. ����� �������� ���� ����(����) �����ϴ� ���
	// 5. ������ ���� ������ ������ ���� ���� ������ ������ �׷��� ����ִ� ���
	// 6. ������ ���� ������ ������ Ư���������� ����(HardwareControl�� ��� �̿�)�ϴ� ���
	// etc
};

#endif