#include "chademo.h"

extern chademo chademo_protocol;
chademo_protocol.charge_enabled = false;
chademo_protocol.parking_position = false;
chademo_protocol.fault = false;
chademo_protocol.contactor_open = false;
chademo_protocol.charger_max_current = 0;
chademo_protocol.charger_current_request = 0;
chademo_protocol.ramped_current_request = 0;
chademo_protocol.target_battery_voltage = 0;
chademo_protocol.charger_output_voltage = 0;
chademo_protocol.charger_output_current = 0;
chademo_protocol.charger_status = 0;
chademo_protocol.state_of_charge = 0;
chademo_protocol.voltage_timeout = 0;
chademo_protocol.current_timeout = 0;

void process_108_message(unsigned int data[2]) {
	chademo_protocol.charger_max_current = data[0] >> 24;
}

void process_109_message(unsigned int data[2]) {
	chademo_protocol.charger_output_voltage = data[0] >> 8;
	chademo_protocol.charger_output_current = data[0] >> 24;
	chademo_protocol.charger_status = (data[1] >> 8) & 0x3f;
}

void set_enabled(bool enabled) {
	chademo_protocol.charge_enabled	= enabled;

	if (!chademo_protocol.chademo_protocol) {
		chademo_protocol.ramped_current_request = 0;
		chademo_protocol.voltage_timeout = 0;
		chademo_protocol.current_timeout = 0;
	}
}

void set_charge_current(unsigned char current) {
	// Оригинальный
	// chademo_protocol.charger_current_request = MIN(current, charger_max_current);
	chademo_protocol.charger_current_request = current;
	if (chademo_protocol.charger_current_request > chademo_protocol.ramped_current_request) {
		chademo_protocol.ramped_current_request++;
	} else if (chademo_protocol.charger_current_request < chademo_protocol.ramped_current_request) {
		chademo_protocol.ramped_current_request--;
	}
}


