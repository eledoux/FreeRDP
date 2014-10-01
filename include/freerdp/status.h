/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 *
 * Status codes, Server Status Info PDU, MS-RDPBCGR 2.2.5.2
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

#ifndef FREERDP_STATUS_H
#define FREERDP_STATUS_H


#ifdef	__cplusplus
extern "C" {
#endif

#define TS_STATUS_FINDING_DESTINATION           0x00000401
#define TS_STATUS_LOADING_DESTINATION           0x00000402
#define TS_STATUS_BRINGING_SESSION_ONLINE       0x00000403
#define TS_STATUS_REDIRECTING_TO_DESTINATION    0x00000404
#define TS_STATUS_VM_LOADING                    0x00000501
#define TS_STATUS_VM_WAKING                     0x00000502
#define TS_STATUS_VM_BOOTING                    0x00000503

#define TS_STATUS_NONE                          0xFFFFFFFF

#ifdef	__cplusplus
}
#endif

#endif	/* FREERDP_STATUS_H */
