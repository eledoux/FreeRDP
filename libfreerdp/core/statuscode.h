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

#ifndef __STATUSCODE_H
#define __STATUSCODE_H

#include <freerdp/freerdp.h>

struct _TS_STATUS
{
	UINT32 code;
	char* name;
	char* info;
};
typedef struct _TS_STATUS TS_STATUS;

#define TS_STATUS_DEFINE(_code)	{ TS_STATUS_##_code , "TS_STATUS_" #_code , TS_STATUS_##_code##_STRING }

void rdp_print_statuscode(UINT32 code);

#endif /* __STATUSCODE_H */
