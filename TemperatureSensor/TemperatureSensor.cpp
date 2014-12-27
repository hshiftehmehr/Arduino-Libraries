#include <Arduino.h>

struct TemperatureSensorDataPoint {
    int temperature;
    long int resistance;
};

struct TemperatureSensorDataPoint temperatureSensorData[] = {
    {-10, 44967},
    {-9, 42897},
    {-8, 40932},
    {-7, 39066},
    {-6, 37294},
    {-5, 35611},
    {-4, 34013},
    {-3, 32494},
    {-2, 31051},
    {-1, 29679},
    {0, 28375},
    {1, 27135},
    {2, 25956},
    {3, 24834},
    {4, 23766},
    {5, 22750},
    {6, 21783},
    {7, 20862},
    {8, 19985},
    {9, 19150},
    {10, 18345},
    {11, 17595},
    {12, 16872},
    {13, 16183},
    {14, 15526},
    {15, 14899},
    {16, 14301},
    {17, 13730},
    {18, 13186},
    {19, 12666},
    {20, 12169},
    {21, 11695},
    {22, 11242},
    {23, 10809},
    {24, 10395},
    {25, 10000},
    {26, 9622},
    {27, 9260},
    {28, 8914},
    {29, 8583},
    {30, 8267},
    {31, 7963},
    {32, 7673},
    {33, 7395},
    {34, 7129},
    {35, 6874},
    {36, 6629},
    {37, 6395},
    {38, 6170},
    {39, 5955},
    {40, 5748},
    {41, 5550},
    {42, 5360},
    {43, 5177},
    {44, 5002},
    {45, 4834},
    {46, 4672},
    {47, 4517},
    {48, 4368},
    {49, 4225},
    {50, 4087},
    {51, 3955},
    {52, 3827},
    {53, 3705},
    {54, 3587},
    {55, 3474},
    {56, 3365},
    {57, 3260},
    {58, 3159},
    {59, 3062},
    {60, 2968},
    {61, 2878},
    {62, 2791},
    {63, 2707},
    {64, 2626},
    {65, 2548},
    {66, 2473},
    {67, 2401},
    {68, 2331},
    {69, 2264},
    {70, 2199},
    {71, 2136},
    {72, 2075},
    {73, 2017},
    {74, 1960},
    {75, 1906},
    {76, 1853},
    {77, 1802},
    {78, 1753},
    {79, 1705},
    {80, 1659}
//    ,{-274, 0} // an impossible option
};

/*
 * Output:
 * Returns sensor temperature in Celcius degrees.
 *
 * Input:
 * P:       Analog input pin number
 * R:       Pull-down resistor value
 * pull-Up: True if pull-up resistor used, False for a pull-down resistor
 * Vin:     High voltage of the circuit. Usually = +5 Volts
 * bits:    Number of ADC bits (10 for Arduino)
 */
float readTemparature(int P, long R, bool pullUp, float Vin, int bits)
{
    float V      = analogRead(P)*(Vin/pow(2, bits));
    long sensorR = (pullUp) ? long(R*V/(Vin-V)) : long(R*(Vin-V)/V);

    const int numDataPoints = signed(sizeof(temperatureSensorData)/sizeof(TemperatureSensorDataPoint)); 
    int i;
    for (i=0; i < numDataPoints; i++)
        if (temperatureSensorData[i].resistance < sensorR)
            break;
    if (i == 0)
        return temperatureSensorData[i].temperature;
    else if (i == numDataPoints)
        return temperatureSensorData[i-1].temperature;
    else {
        return temperatureSensorData[i].temperature +
               float(temperatureSensorData[i].resistance-sensorR)/
               float(temperatureSensorData[i-1].resistance-temperatureSensorData[i].resistance);
    }
}

