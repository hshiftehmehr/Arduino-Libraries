/*
 * Output:
 * Returns sensor temperature in Celcius degrees.
 *
 * Input:
 * P:       Analog input pin number
 * R:       Pull-down resistor value
 * pull-Up: True if pull-up resistor used, False for a pull-down resistor
 * Vcc:     High voltage of the circuit. Usually = +5 Volts
 * bits:    Number of ADC bits (10 for Arduino)
 */
float readTemparature(int, long, bool, float, int);

