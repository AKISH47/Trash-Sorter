# Trash-Sorter
Using a tensorflow object classication model to sort trash.

# Images/Videos
Uses pretrained model on github ---> https://github.com/supriya811106/Garbage-Classification-System/tree/master
1.![Screenshot from 2024-07-23 20-11-10](https://github.com/user-attachments/assets/bd4eaeee-d7ff-4be2-b372-341424997673)
2.![20240723_201924](https://github.com/user-attachments/assets/560ea39f-e967-403b-b497-c4731a541e3c)

1.Running python file on terminal
2.Picture of Setup


# Parts Used:
1. CNC Shield
2. Arduino Mega 2560
3. Servo Motor
4. IR Sensor
5. Stepper Motor
6. Conveyor belt setup

# How it works:
1. When ir sensor detects an object, it sends "trash detected" through the serial port.
2. If the arduino sends "trash detected", the python code reads the frame of the webcam.
3. The results are sent back to the arduino
4. The converyor belt system moves a certain distance based on whether the trash is reyclable or unrecyclable. 
