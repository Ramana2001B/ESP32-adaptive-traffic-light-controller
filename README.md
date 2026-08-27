# ESP32 Adaptive Traffic Light Controller

## Overview

An ESP32-based adaptive traffic light controller that monitors vehicle density using IR sensors and dynamically selects the lane that should receive the green signal.

## Features

* ESP32-based traffic control system
* 12 IR sensors for vehicle detection across four lanes
* Real-time vehicle counting
* Adaptive lane selection based on vehicle counts
* Red and green LED traffic signal control
* Serial monitoring of vehicle counts and signal status

## Hardware Used

* ESP32
* 12 × IR sensors
* Red and green LEDs
* Connecting wires
* Breadboard

## Working

The IR sensors detect vehicles in the four traffic lanes: North, South, East, and West. The ESP32 maintains separate vehicle counts for each lane. When the current lane completes its turn, the controller compares the vehicle counts of the remaining lanes and selects the lane with the highest traffic demand for the next green signal.

## Pin Configuration

| Lane  | IR Sensors      | Red LED | Green LED |
| ----- | --------------- | ------- | --------- |
| North | GPIO 19, 23, 13 | GPIO 5  | GPIO 18   |
| East  | GPIO 12, 14, 17 | GPIO 0  | GPIO 4    |
| South | GPIO 26, 25, 34 | GPIO 16 | GPIO 17   |
| West  | GPIO 33, 32, 35 | GPIO 15 | GPIO 2    |

## Technologies

* Embedded C/C++
* ESP32
* Arduino Framework
* IR Sensor Interfacing
* Digital GPIO
* Serial Communication

## Project Status

Prototype implementation. The controller code will be updated as the project is further developed and optimized.
