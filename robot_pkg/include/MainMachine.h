#pragma once
#ifndef MAINMACHINE_H
#define MAINMACHINE_H

#include <unordered_map>
#include <string>
#include <vector>

#include "ros/ros.h"
#include "tf/transform_listener.h"


enum class mode;
class OperatingMode;
class Logger;

class MainMachine {
private:
//==================
struct DestinationInfo{
	DestinationInfo(double x, double y, double yaw, int bookshelfID):x(x),y(y),yaw(yaw),bookshelfID(bookshelfID){}

	double x;
	double y;
	double yaw;
	int bookshelfID;
};
//==================

public:
	MainMachine(ros::NodeHandle& n);
	~MainMachine();
	void StartMainLoop();
	
	void test();

	double getX() const;
	double getY() const;
	double getYaw() const;

	double getDestX() const;
	double getDestY() const;
	double getDestYaw() const;
	bool isDestBookshelf() const;
	int getBookshelfID() const;
	
	void updatePosition();
	bool nextDestination();

	void moveForward() const;
	void moveBackward() const;
	void moveFrontRight() const;
	void moveFrontLeft() const;
	void moveBackRight() const;
	void moveBackLeft() const;

	void turnRight() const;
	void turnLeft() const;
	void stop() const;

	void cameraOn() const;
	void cameraOff() const;


private:
	mode currentMode;
	std::unordered_map<mode, OperatingMode*> Operation;
	Logger* const logger;

	tf::TransformListener TFlistener;
	double x;
	double y;
	double yaw;
  
	ros::NodeHandle& n;
	ros::Publisher motorPub;
	ros::Publisher cameraTogglePub;

	void move(const std::string& cmd) const;
	void changeMode(mode nextMode);

	std::vector<DestinationInfo> destinations;

	int destIdx;


};
#endif
