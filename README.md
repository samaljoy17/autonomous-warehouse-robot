# Autonomous Warehouse Robot Pathfinding & Obstacle Simulator

## 1. Project Overview

This project implements a Linux-based warehouse robot simulator using C++ and a Linux virtual character device driver.

The robot navigates through a warehouse represented as a grid and calculates a safe path while avoiding obstacles.

## 2. Objectives

- Simulate warehouse navigation
- Implement autonomous pathfinding
- Demonstrate C++ programming
- Demonstrate Linux system programming
- Demonstrate Linux device-driver communication
- Demonstrate IPC
- Implement testing and logging

## 3. Technologies

- Linux
- C++
- C
- Linux Kernel Module
- BFS
- STL
- Git
- GitHub

## 4. Architecture

The system consists of:

1. Warehouse
2. Robot
3. PathFinder
4. Sensor Interface
5. Linux Device Driver
6. IPC Monitor
7. Logger

## 5. Project Structure

```text
warehouse_robot/
├── include/
├── src/
├── driver/
├── tests/
├── docs/
├── logs/
├── Makefile
└── README.md
