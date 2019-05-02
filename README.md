# ISOT
I2C-Is Something Out There

This Source Code is dedicated to persons, which works hard and becomes desperate on I2C-Bus delivered on XMC4500 ARM CORTEX-M Device from Infineon with CodeEngine DAVE V4.

Short explanation:
Scans all available I2C-Adresses and detect wired device(s) on the bus to display the responding I2C-Adress on LCD in a loop.

Detailed explanation:
The XMC Device would remain in the while loop - tx-completedif a wrong addressed or bad responding device (NACK) occurs. To circument this kiss of death , a Software Watchdog is implemented and calls A Callback Function in which, the I2C Bus is stopped and reinitialized. So next address request could be performed.
Therefore all I2C-IRQs are enabled and provides Call back routines.
