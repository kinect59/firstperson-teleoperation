/*
*   This file is part of firstperson-telecontrol.
*
*    firstperson-telecontrol is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    firstperson-telecontrol is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with firstperson-telecontrol.  If not, see <http://www.gnu.org/licenses/>.
*
*	 Authors: Lars Fritsche, Felix Unverzagt, Roberto Calandra
*	 Created: July, 2015
*/

#ifndef YARP_ADAPTER
#define YARP_ADAPTER

#include <yarp/os/Network.h>
#include <yarp/os/Time.h>
#include <yarp/os/ResourceFinder.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/ITorqueControl.h>
#include <yarp/dev/IControlMode.h>
#include <yarp/dev/IPositionControl.h>
#include <yarp/dev/IEncoders.h>
#include <yarp/math/Math.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>


using namespace std;
using namespace yarp::os;
using namespace yarp::dev;
using namespace yarp::math;

class YarpAdapter {

public: 

	static const int MOVE_LEFT_ARM = 0;
	static const int MOVE_RIGHT_ARM = 1;
	static const int MOVE_HEAD = 2;
	static const int MOVE_TORSO = 3;

	YarpAdapter();
	~YarpAdapter();

	int close();
	int move(int bodyPart, double* refs);
	int move(int bodyPart, int jointId, double angle);
	void setVelocityNormal();
	void setVelocityLow();
	double* getJoints(int bodyPart);
	int getDof(int bodyPart);
	bool isActivated(int bodyPart);
	bool isDirect(int bodyPart);
	void writeToOutput(double* handValues);
	void resetVibration();
	double* readGloveVibrationInput();

private:
	void setMode(bool finished);
	void initialize();
	void initializeDevice(int bodyPart, string remotePorts, string localPorts, string device);
	void setSingleVelocityLow(int bodyPart);
	void setSingleVelocityNormal(int bodyPart);
	void initializePorts();
	double lastTime = 0;

};

#endif
