# Wires
Almost all cables in the project, consist of either 2 or 3 inner wires. (With the exception of the 7-pin cable for the front panel)
All the wires are made on a 1-1 basis, where each pin is connected to the same pin in the other end:

![image](https://user-images.githubusercontent.com/22596587/125455171-542be621-c9ab-4f54-a2a9-1f24d5a38f21.png)

This makes it so that the same wires can be used for almost all ports (except if its a type D wire)

# Terminals
Pretty much all plugs is GX16-3-pin aviation plugs.
There are some different setups, for different terminals. But in general, they are intented to share some commonality.

All in all there are 3 different 3-proned terminals from the main controller:
## Type A
Type A is the basic variant, consisting of power and a single signal wire.

![plugTypeA](https://user-images.githubusercontent.com/22596587/125454228-3b18938e-53ed-40c5-bf35-3c5e0b1f5a2f.png)

## Type B
Type B is for motor controllers, where two are needed. One that has the GND plug, and one that has the +12v plug.

![PlugTypeB](https://user-images.githubusercontent.com/22596587/125454356-154c5bef-db95-4b7e-8704-8a034f489343.png)

## Type C
Type C is for special future expansion, where the RX/TX pins can be used.

![PlugTypeC](https://user-images.githubusercontent.com/22596587/125454462-66fce885-b1c6-446f-8707-3f72dfd88c45.png)

## Type D
There are also some wires and terminals, that only use two terminals (usually from a module to the thing being controlled, e.g. from a Transistor Module to LEDs)
They are esentially no different than the Base terminal, except there are no Signal:

![PlugTypeD](https://user-images.githubusercontent.com/22596587/125454556-fcc1ed92-2662-498f-85f8-91c4c628aa47.png)

(Note, that i removed the third pron from the connectors for all Type D terminals, so not to cause confusion)
