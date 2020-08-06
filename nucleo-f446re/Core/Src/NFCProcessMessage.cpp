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

//#include "EmbeddedProto_service.h"
#include "NFCProcessMessage.h"
#include "nfc_messages.h"
#include "NFCReadBuffer.h"
#include "NFCWriteBuffer.h"
#include <Errors.h>

#include <cstring>
#include "stm32f4xx_nucleo.h"

#define NAME_LENGTH 32


void process_nfc_tag(const nfc<NAME_LENGTH>& nfc);

extern "C" {
int logUsart(const char* format, ...);
#define platformLog(...)                              logUsart(__VA_ARGS__)                         //!< Log  method
}



NFCReadBuffer read_buffer;
NFCWriteBuffer write_buffer;
nfc<NAME_LENGTH> nfc_tag;

//! Function receives message from tag and deserializes it
/*!
 * \param[in] byte Protobuf serialized message .
 * \param[in] data_length Length of NFC EmbeddedProto message.
 */
void nfc_read_tag(const uint8_t *byte, uint8_t data_length){
	//Protobuf message length is stored in first byte
	uint8_t n_bytes = byte[0]+1;

	if(n_bytes <= data_length){

		for(uint8_t i=1; i<n_bytes; i++){
			read_buffer.push(byte[i]);
		}

		// Deserialize the data received.
		auto deserialize_status = nfc_tag.deserialize(read_buffer);
		if(::EmbeddedProto::Error::NO_ERRORS == deserialize_status) {
			// Process the command.
			process_nfc_tag(nfc_tag);
		}
	}

    read_buffer.clear();
}

//! Function builds serialized protobuf message.
//! And copies the message to a buffer.
/*!
 * \param[out] buf Protobuf serialized message .
 * \param[out] len Length of NFC EmbeddedProto message.
 */
void nfc_write_tag(uint8_t* buf, uint32_t *len)
{
	uint32_t message_len_index = write_buffer.get_size();
	write_buffer.push(0); //placeholder for buffer length

	nfc_tag.set_clearance(nfc<NAME_LENGTH>::CLEARANCE::DEPARTMENT_B);

	char name_input[] = "EmbeddedProto";

	for(uint8_t i=0; i<strlen(name_input); i++){
		nfc_tag.mutable_name()[i] = name_input[i];
	}

	// Serialize the data.
	auto serialization_status = nfc_tag.serialize(write_buffer);
	if(::EmbeddedProto::Error::NO_ERRORS == serialization_status)
	{
		write_buffer.get_data()[message_len_index] = write_buffer.get_size()-1;

		for (uint8_t i=0; i<write_buffer.get_size(); i++){
			buf[i] = write_buffer.get_data()[i];
		}

		*len = write_buffer.get_size();
	}

	write_buffer.clear();
}

//! The functions takes a protobuf message and responds to it.
/*!
 * \param[in] NFC The nfc message.
 */
void process_nfc_tag(const nfc<NAME_LENGTH>& NFC)
{
	const char *name =  NFC.get_name();

	//Print clearance and name
	platformLog("Name: %s\r\n", name);

	switch(NFC.get_clearance()){

		case nfc<NAME_LENGTH>::CLEARANCE::NO_ACCESS:
		platformLog("Clearance: No Access\r\n");
		break;

		case nfc<NAME_LENGTH>::CLEARANCE::DEPARTMENT_A:
		platformLog("Clearance: Department A\r\n");
		break;

		case nfc<NAME_LENGTH>::CLEARANCE::DEPARTMENT_B:
		platformLog("Clearance: Department B\r\n");
		break;

		case nfc<NAME_LENGTH>::CLEARANCE::DEPARTMENT_C:
		platformLog("Clearance: Department C\r\n");
		break;

		default:
			break;
	}
}





