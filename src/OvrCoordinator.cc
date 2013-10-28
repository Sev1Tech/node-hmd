#include <node.h>

#include "OVR.h"
#include "OvrCoordinator.h"

using namespace v8;

OvrCoordinator* OvrCoordinator::instance = NULL;

OvrCoordinator::OvrCoordinator() {
	OVR::System::Init();
	pFusionResult = new OVR::SensorFusion();
	pManager = *OVR::DeviceManager::Create();
}

OvrCoordinator::~OvrCoordinator() {
	pSensor.Clear();
    pHMD.Clear();
	pManager.Clear();

	delete pFusionResult;

	OVR::System::Destroy();
}

OvrCoordinator* OvrCoordinator::getInstance() {
	if(!instance) {
		instance = new OvrCoordinator;
	}

	return instance;
}
