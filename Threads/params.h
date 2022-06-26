#include <stdbool.h>

enum _modes {
	MOD_OFF = 0,
	MOD_CHARGE_START,
	MOD_CHARGE_LOCK,
	MOD_CHARGE,
	MOD_CHARGE_END
};

struct params_struct {
	// controller params
	int cpu_load;
	int temperature;
	int operation_mode;
};

struct digio_struct {
	bool first_charger_key;
	bool second_charger_key;
};

typedef struct params_struct params;
typedef struct digio_struct digital_input_output;
