/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 *
 * statusCode, Server Status Info PDU, MS-RDPBCGR 2.2.5.2
 *
 * Copyright 2014 Hewlett-Packard Development Company, L.P.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <freerdp/utils/debug.h>

#include "statuscode.h"

#define TS_STATUS_FINDING_DESTINATION_STRING \
		"The destination computer is being located."

#define TS_STATUS_LOADING_DESTINATION_STRING \
		"The destination computer is being prepared for use."

#define TS_STATUS_BRINGING_SESSION_ONLINE_STRING \
		"The destination computer is being prepared to accept a remote connection."

#define TS_STATUS_REDIRECTING_TO_DESTINATION_STRING \
		"The client is being redirected to the destination computer."

#define TS_STATUS_VM_LOADING_STRING \
		"The destination virtual machine image is being loaded."

#define TS_STATUS_VM_WAKING_STRING \
		"The destination virtual machine is being resumed from sleep or hibernation."

#define TS_STATUS_VM_BOOTING_STRING \
		"The destination virtual machine is being booted."

/* Special codes */
#define TS_STATUS_NONE_STRING ""

static const TS_STATUS TS_STATUS_CODES[] =
{
		TS_STATUS_DEFINE(FINDING_DESTINATION),
		TS_STATUS_DEFINE(LOADING_DESTINATION),
		TS_STATUS_DEFINE(BRINGING_SESSION_ONLINE),
		TS_STATUS_DEFINE(REDIRECTING_TO_DESTINATION),
		TS_STATUS_DEFINE(VM_LOADING),
		TS_STATUS_DEFINE(VM_WAKING),
		TS_STATUS_DEFINE(VM_BOOTING),

		TS_STATUS_DEFINE(NONE)
};

const char* freerdp_get_status_info_string(UINT32 code)
{
	const TS_STATUS* tsStatus;

	tsStatus = &TS_STATUS_CODES[0];

	while (tsStatus->code != TS_STATUS_NONE)
	{
		if (tsStatus->code == code)
		{
			return tsStatus->info;
		}

		tsStatus++;
	}

	return "Unknown status code.";
}

const char* freerdp_get_status_info_name(UINT32 code)
{
	const TS_STATUS* tsStatus;

	tsStatus = &TS_STATUS_CODES[0];

	while (tsStatus->code != TS_STATUS_NONE)
	{
		if (tsStatus->code == code)
		{
			return tsStatus->name;
		}

		tsStatus++;
	}

	return "TS_STATUS_UNKNOWN";
}

void rdp_print_statuscode(UINT32 code)
{
	const TS_STATUS* tsStatus;

	tsStatus = &TS_STATUS_CODES[0];

	while (tsStatus->code != TS_STATUS_NONE)
	{
		if (tsStatus->code == code)
		{
			DEBUG_MSG("%s (0x%08X): %s", tsStatus->name, tsStatus->code, tsStatus->info);
			return;
		}

		tsStatus++;
	}

	DEBUG_WARN("TS_STATUS_UNKNOWN (0x%08X): Unknown status code.", code);
}
