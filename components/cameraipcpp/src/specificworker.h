/*
 *    Copyright (C)2019 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
       \brief
       @author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
<<<<<<< HEAD
#include <opencv2/opencv.hpp>
#include <curl/curl.h>

#define URL "http://192.168.0.100:88/cgi-bin/CGIStream.cgi?cmd=GetMJStream&usr=guest&pwd=smpt00"


struct MemoryStruct
{
    char *memory;
    size_t size;
    size_t begin, end;
};
=======
#include <innermodel/innermodel.h>
#include <ipcamreader.h>
>>>>>>> eea2392695743c234d5db54b3b0e434d726fbb1b

class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
	SpecificWorker(TuplePrx tprx);
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);

	void CameraSimple_getImage(TImage &im);

public slots:
	void compute();
	void initialize(int period);

private:
<<<<<<< HEAD
	CURL *curl_handle;
    CURLcode res;
	
=======
	IPCamReader cam;
>>>>>>> eea2392695743c234d5db54b3b0e434d726fbb1b

};

#endif