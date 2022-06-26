#ifndef CHADEMO_H
#define CHADEMO_H

struct chademo_struct {
	// controller params
	bool charge_enabled;
	bool parking_position;
	bool fault;
	bool contactor_open;
	unsigned char charger_status;
	unsigned char charger_max_current;
	unsigned char charger_current_request;
	unsigned int ramped_current_request;
	unsigned short target_battery_voltage;
	unsigned short charger_output_voltage;
	unsigned char charger_output_current;
	unsigned char state_of_charge; // емкость батареи
	unsigned int voltage_timeout;
	unsigned int current_timeout;
};

typedef struct chademo_struct chademo;
static chademo chademo_protocol;

void process_108_message(unsigned int data[2]);
void process_109_message(unsigned int data[2]);

// отправка сообщений через can каждый 100 мс
void send_messages();
void set_target_battery_voltage(unsigned short voltage) { chademo_protocol.target_battery_voltage = voltage; }
void set_charge_current(unsigned char current);
void set_enabled(bool enabled);
void set_park_position(bool pos) { chademo_protocol.parking_position = pos; }
void set_contactor(bool state) { chademo_protocol.contactor_open  = state; }
void set_general_fault() { chademo_protocol.fault = true; }
// установка емкости батареи ???
void set_soc();
int get_charger_output_voltage() { return chademo_protocol.charger_output_voltage; }
int get_charger_output_current() { return chademo_protocol.charger_output_current; }
int get_charger_max_current() { return chademo_protocol.charger_max_current; }
int get_charger_status() { return chademo_protocol.charger_status; }
bool connector_locked() { return (chademo_protocol.charger_status & 0x4) != 0; }
bool connector_stop_request() { return (chademo_protocol.charger_status & 0x2A) != 0; }
unsigned char get_ramped_current_request() { return chademo_protocol.ramped_current_request; }
// Должна вызываться каждые 100 мс
void check_sensor_deviation(unsigned short internal_voltage);

#endif // CHADEMO_H
