
![alt text](https://embeddedproto.com/wp-content/uploads/2022/04/Embedded_Proto.png "Embedded Proto Logo")


Copyrights 2020-2021 Embedded AMS B.V. Amsterdam, [www.EmbeddedAMS.nl](https://www.EmbeddedAMS.nl), [info@EmbeddedAMS.nl](mailto:info@EmbeddedAMS.nl)


Looking for a more elaborate description of this example? Please visit: nfc example link


# Introduction

This repository hosts example code for Embedded Proto, the embedded implementation of Google Protocol Buffers. It is a simple example showing how a microcontroller can use Embedded Proto to be able to communicate between devices using NFC in a structured way.


This example uses NFC to read and write a protobuf message from/to a NFC tag. 

![alt text](https://embeddedproto.com/wp-content/uploads/2020/08/NFC_hardware.jpg "NFC setup")

This example makes use of a NUCLEO-F446RE, a X-NUCLEO-NFC05A1 nfc evaluation board and ST25TA tags, all made by ST Microelectronics. The microcontroller is based on an ARM Cortex-M4 processor. To build the source code and program the hardware STM32CubeIDE has been used. 

The microcontroller uses a serial port to print information to a terminal such as PuTTY.


# Installation

1. Install STM32CubeIDE if you have not already.
2. Install a terminal, such as PuTTY.
3. Install the dependencies required by Embedded Proto. They are listed [here](https://github.com/Embedded-AMS/EmbeddedProto).
4. Checkout this example repository including the submodule of Embedded Proto: `git clone --recursive https://github.com/Embedded-AMS/EmbeddedProto_Example_STM32_NFC.git`.
5. Setup the environment required for Embedded Proto by running the setup script: `python setup.py`.

The setup script already does it for you but you can regenerate the source code using the `python setup.py --generate` parameter. This is required when you have changed the \*.proto file.


# Running the code

First connect the NFC evaluation board, X-NUCLEO-NFC05A1, to the NUCLEO. Then connect the NUCLEO via the usb programmer and use STM32CubeIDE to build and program the microcontroller on it. Next open a terminal such as PuTTY and setup a serial connection (baudrate 115200) using the comport that is used by the NUCLEO.
You should see something like this:

![alt text](https://embeddedproto.com/wp-content/uploads/2020/08/NFC_terminal_1.jpg "Terminal screenshot of NFC menu")

For more information about what the code does and how to control the application, please visit: [An NFC example with Embedded Proto](https://embeddedproto.com/nfc-example-with-embedded-proto/)

Have fun!
