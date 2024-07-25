# Hexapod Robot

## Overview

This project involves the creation of a hexapod robot with six legs, each having three joints (distal, mid, and proximal). The robot's movement and coordination are managed through a custom C++ program running on a Pimoroni microcontroller.

### Hardware Components

* **Microcontroller:** This project uses the [Pimoroni Servo 2040](https://shop.pimoroni.com/products/servo-2040?variant=39800591679571) microcontroller.
* **Servos:** The robot uses 18 [MG996R 55g Metal Gear Torque Digital Servo Motors](https://www.amazon.com/dp/B07MFK266B?ref=ppx_pop_mob_ap_share&th=1).
* **3D Printed Model:** The hexapod structure is based on [SimpleRobotics' 3D printed model available on MakerWorld](https://makerworld.com/en/models/523424#profileId-440772).

### Software Components

* **Pimoroni C++ Libraries:** The project utilizes [Pimoroni's C++ libraries](https://github.com/pimoroni/pimoroni-pico/tree/main/libraries).
  * Set up for Pico C++ SDK followed these [instructions](https://github.com/pimoroni/pimoroni-pico/blob/main/setting-up-the-pico-sdk.md).

## Project Structure

### Files

* **constants.h:** Contains constants used throughout the project.
* **hexapod.cpp & hexapod.hpp:** Defines the Hexapod class, which manages the overall robot operations.
* **leg.cpp & leg.hpp:** Defines the Leg class, which manages individual leg operations.
* **servoWrapper.cpp & servoWrapper.hpp :** Provides a unified interface to handle both regular servos and servo clusters seamlessly.
* **main.cpp:** The main script to initialize and run the hexapod robot.
