/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <algorithm>

#include "HMDDeviceInfo.h"

HMDDeviceInfo::HMDDeviceInfo() {
	std::fill(this->displayDeviceName, this->displayDeviceName + MAX_DESCRIPTION_LENGTH, '\0');
	std::fill(this->productName, this->productName + MAX_DESCRIPTION_LENGTH, '\0');
	std::fill(this->manufacturer, this->manufacturer + MAX_DESCRIPTION_LENGTH, '\0');
}