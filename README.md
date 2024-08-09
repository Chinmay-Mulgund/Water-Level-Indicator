# Water-Level-Indicator

## Overview
- The Arduino sketch measures the water level in a tank using an ultrasonic distance sensor.
- The sensor's readings are used to calculate the water level percentage and determine the tank's status.

## Components
- Ultrasonic Sensor: Measures distance to the water surface.
- Arduino Board: Processes sensor data and performs calculations.

## Pin Configuration
- Trigger Pin: GPIO4 (D4)
- Echo Pin: GPIO2 (D2)

## Parameters
- `maxDistance`: Maximum measurable distance (450 cm).
- `minDistance`: Minimum measurable distance (20 cm).
- `timeout`: Timeout for `pulseIn` function (13200 µs).
- `fullDistance`: Distance when the tank is full (45 cm).
- `emptyDistance`: Distance when the tank is empty (115 cm).

## Code Explanation
1. **Initialization**:
   - `Serial.begin(115200)`: Starts serial communication at 115200 baud.
   - `pinMode(triggerPin, OUTPUT)`: Sets the trigger pin as an output.
   - `pinMode(echoPin, INPUT)`: Sets the echo pin as an input.

2. **Measuring Distance**:
   - The trigger pin is pulsed to send an ultrasonic pulse.
   - The echo pin receives the reflected pulse.
   - The duration of the pulse is measured to calculate the distance.

3. **Calculating Water Level**:
   - If the distance is within the valid range, it is mapped to a percentage (0% to 100%).
   - The water level percentage is printed to the Serial Monitor.
   - The tank status is updated based on the water level percentage:
     - 100%: "Tanker Full"
     - 0%: "Tanker Empty"
     - Intermediate values: "In Between"

4. **Delay**:
   - `delay(100)`: Waits 100 milliseconds before the next measurement.

## Serial Monitor Output
The Serial Monitor will display:
- Distance: The measured distance in centimeters.
- Water Level: The calculated percentage of water in the tank.
- Tank Status: The status of the tank (Full, Empty, or In Between).

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
