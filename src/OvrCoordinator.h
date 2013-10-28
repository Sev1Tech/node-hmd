#ifndef OVRCOORDINATOR_H
#define OVRCOORDINATOR_H

#include <node.h>

#include "OVR.h"

using namespace v8;

class OvrCoordinator {
	private:
		// Singleton Instance
  		static OvrCoordinator* instance;

  		// Instance Properties
		OVR::Ptr<OVR::DeviceManager>	pManager;
		OVR::Ptr<OVR::HMDDevice>		pHMD;
		OVR::Ptr<OVR::SensorDevice>		pSensor;
		OVR::SensorFusion*				pFusionResult;

  		// Class Methods
		OvrCoordinator();
  		~OvrCoordinator();

  	public:
  		static OvrCoordinator* getInstance();
};

#endif