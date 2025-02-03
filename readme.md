# Smart home simulator
## Application
This is an OOP written application using C++ only. There is firs class "Smart Device" in which are basic settings like name, id and network settings. each class from each family of smart devices inherits from SmartDevice. At this moment there are 4 possible to add smart devices: Bulb, Socekt, Thermometer and Thermostat.
All of the devices are controlled from smartManager class.
## Manual:
To build project go to main directory and use:
```
$ make
```
To clean build go to main directory and use:
```
$ make clean
```
To run the application go to /build and run:
```
$ ./SmartHomeSimulator.exe
```