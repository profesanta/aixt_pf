// This Arduino code was automatically generated by Aixt Project
// Device = 2ATPO-AIWB2
// Board = Ai-WB2-32S-Kit
// Backend = arduino

#define time__sleep_ms(MS)    delay(MS)
#define pin__out		OUTPUT
#define pin__in			INPUT
#define pin__in_pullup	INPUT_PULLUP
#define pin__high(PIN_NAME)   digitalWrite(PIN_NAME, HIGH)
#define pin__low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)
#define pin__read(PIN_NAME)   digitalRead(PIN_NAME)
#define pin__setup(PIN_NAME, MODE)    pinMode(PIN_NAME, MODE)
#define pin__write(PIN_NAME, VALUE)   digitalWrite(PIN_NAME, VALUE)
#define uart__available(MESSAGE)	Serial.available(MESSAGE)
#define uart__print_0(MESSAGE)	Serial.print(MESSAGE)
#define uart__print_1(MESSAGE)	Serial1.print(MESSAGE)
#define uart__print_x(UART_NUMBER, MESSAGE)		uart__print_ ## UART_NUMBER (MESSAGE)
#define SEL_UART_PRINT(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__print(...) SEL_UART_PRINT(__VA_ARGS__, uart__print_x, uart__print_0)(__VA_ARGS__)
#define uart__println_0(MESSAGE)	Serial.println(MESSAGE)
#define uart__println_1(MESSAGE)	Serial1.println(MESSAGE)
#define uart__println_x(UART_NUMBER, MESSAGE)		uart__println_ ## UART_NUMBER (MESSAGE)
#define SEL_UART_PRINTLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__println(...) SEL_UART_PRINTLN(__VA_ARGS__, uart__println_x, uart__println_0)(__VA_ARGS__)
#define uart__read_0()	Serial.read()
#define uart__read_1()	Serial1.read()
#define uart__read_x(UART_NUMBER)	uart__read_ ## UART_NUMBER ## .read()
#define SEL_UART_READ(_0, _1, MACRO_NAME, ...) MACRO_NAME
#define uart__read(...) SEL_UART_READ(_0 __VA_OPT__(,) __VA_ARGS__, uart__read_x, uart__read_0)(__VA_ARGS__)
#define uart__ready_0()	Serial.ready()
#define uart__ready_1()	Serial1.ready()
#define uart__ready_x(UART_NUMBER)	uart__ready_ ## UART_NUMBER ## .ready()
#define SEL_UART_READY(_0, _1, MACRO_NAME, ...) MACRO_NAME
#define uart__read(...) SEL_UART_READY(_0 __VA_OPT__(,) __VA_ARGS__, uart__ready_x, uart__ready_0)(__VA_ARGS__)
#define uart__setup(BAUD_RATE)   Serial.begin(BAUD_RATE)
#define uart__setup_0(BAUD_RATE)					Serial.begin(BAUD_RATE)
#define uart__setup_1(BAUD_RATE)					Serial1.begin(BAUD_RATE)
#define uart__setup_x(UART_NUMBER, BAUD_RATE)		uart__setup_ ## UART_NUMBER (BAUD_RATE)
#define SEL_UART_SETUP(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__setup(...) SEL_UART_SETUP(__VA_ARGS__, uart__setup_x, uart__setup_0)(__VA_ARGS__)

void main__init();

void time__init();

void pin__init();

void uart__init();

enum main____pin_names {
	IO11 = 11,
	IO14 = 14,
	IO17 = 17,
	IO3 = 3,
	IO4 = 4,
	IO5 = 5,
	RX = 7,
	TX = 16,
	IO12 = 12,
};

void main__init() {
	time__init();
	pin__init();
	uart__init();
	
}

void time__init() {
}

void pin__init() {
}

void uart__init() {
}

void setup() {
	main__init();
	uart__setup(115200);
	pin__setup(4, pin__out);
	pin__setup(5, pin__out);
	pin__setup(12, pin__out);
}

void loop() {
	uart__println_0("\r\n Este programa realiza unas funciones establecidas:");
	uart__println_0("\r\n Oprimiendo la letra A, activa la salida  del pin GPIO4.");
	uart__println_0("\r\n Oprimiendo la letra B, activa la salida  del pin GPIO5.");
	uart__println_0("\r\n El piloto (led) Rojo indica que esta esperando instrucciones.");
	uart__println_0("\r\n Esperando instrucciones: \r\n");
	pin__high(12);
	time__sleep_ms(500);
	pin__low(12);
	time__sleep_ms(500);
	int32_t x = 0;
	x = uart__available();
	if(x > 0) {
		char command = ' ';
		command = uart__read_0();
		if(command == 'A') {
			uart__println_0("\r\n Comando A recibido. \r\n");
			uart__println_0("\r\n Realizando acciÃ³n A. \r\n");
			pin__high(4);
			time__sleep_ms(5000);
			pin__low(4);
			time__sleep_ms(1000);
			uart__println_0("\r\n Proceso A finalizado. \r\n");
		}
		if(command == 'B') {
			uart__println_0("\r\n Comando B recibido. \r\n");
			uart__println_0("\r\n Realizando acciÃ³n B. \r\n");
			pin__high(5);
			time__sleep_ms(5000);
			pin__low(5);
			time__sleep_ms(1000);
			uart__println_0("\r\n Proceso B finalizado. \r\n");
		}
		else {
			pin__high(12);
			time__sleep_ms(1000);
			pin__low(12);
			time__sleep_ms(1000);
		}
	}
}
