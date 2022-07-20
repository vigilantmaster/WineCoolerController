# WineCoolerController
A controller for a wine cooler box.

Background:
Got a wine cooler box with the electronics not working. Removed the control board and decided to implement my own diy.

Process:

1. Take out the current control board and try to fix it.
    a. After bridging the fuse with a wire and turning it on again the board burnt the wire put in and it was not worth fixing.

2.  Put in Arduino control circuitry.
    a. Attempt 1 with just transistor was unsuccessful with a burnt Arduino and transistor.
    b. Attempt 2 with a relay controlled by a transistor and lower voltage.

System:

Arduino:
Reads transistor and sends signal to transistor to turn off or on.
Calculated values used are 14000 for about 64 degrees farenheit and 20000 for about 59 degrees farenheit.
A really simple average is taken to account for extreme fluctuations in resistance reading.

The attempt is to keep it within the range for both wine types.

The temperatures chosen are based on https://winefolly.com/tips/white-red-wine-temperature/

Serve red wines slightly cooler than room temperature, between 62–68 degrees F (15–20 °C).

Generally speaking, serve white wines slightly warmer than fridge temperature, between 49-55 degrees F (7–12 °C).
