/*
 *  Copyright (C) 2020 Embedded AMS B.V. - All Rights Reserved
 *
 *  This file is part of Embedded Proto.
 *
 *  Embedded Proto is open source software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, version 3 of the license.
 *
 *  Embedded Proto  is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Embedded Proto. If not, see <https://www.gnu.org/licenses/>.
 *
 *  For commercial and closed source application please visit:
 *  <https://EmbeddedProto.com/license/>.
 *
 *  Embedded AMS B.V.
 *  Info:
 *    info at EmbeddedProto dot com
 *
 *  Postal adress:
 *    Johan Huizingalaan 763a
 *    1066 VH, Amsterdam
 *    the Netherlands
 */

#ifndef SRC_BLEPROCESSCOMMAND_H_
#define SRC_BLEPROCESSCOMMAND_H_

#include <stdint.h>

 #ifdef __cplusplus
 #define EXTERNC extern "C"
 #else
 #define EXTERNC
 #endif


//EXTERNC void ble_receive_command(uint8_t *byte, uint8_t data_length);

//EXTERNC void ble_send_sensor(void);

EXTERNC void nfc_read_tag(uint8_t *byte, uint8_t data_length);

//EXTERNC uint8_t* nfc_write_tag(uint32_t *len);
EXTERNC void nfc_write_tag(uint8_t *buf, uint32_t *len);






#endif /* SRC_BLEPROCESSCOMMAND_H_ */
