/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "HMDDeviceInfo.h"

HMDDeviceInfo::HMDDeviceInfo() {
	memset(this->displayDeviceName, '\0', MAX_DESCRIPTION_LENGTH);
	memset(this->productName, '\0', MAX_DESCRIPTION_LENGTH);
	memset(this->manufacturer, '\0', MAX_DESCRIPTION_LENGTH);
}