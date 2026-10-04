# Stage 3 – System Design & Architecture

## 1. Project Architecture

The project consists of the following major modules:

1. Warehouse Module
2. Robot Module
3. PathFinder Module
4. Logger Module
5. Linux Device Driver Module
6. Testing Module

## 2. Warehouse Module

Responsible for:

- Creating warehouse grid
- Adding obstacles
- Checking valid positions
- Checking blocked positions

## 3. Robot Module

Responsible for:

- Maintaining robot position
- Updating robot position
- Providing current X and Y coordinates

## 4. PathFinder Module

Responsible for:

- Finding a route
- Avoiding obstacles
- Using Breadth First Search

## 5. Logger Module

Responsible for:

- Recording important application events
- Maintaining development logs

## 6. Data Structures

The project uses:

- Vector
- Queue
- Map
- Pair

## 7. Algorithm

Breadth First Search (BFS) is used for pathfinding.

## 8. Development Environment

Operating System:
Linux

Programming Languages:
C and C++

Compiler:
G++

Version Control:
Git

Repository:
GitHub

## 9. Current Implementation

The initial C++ prototype has been implemented.

The following functionality is currently available:

- Warehouse creation
- Obstacle creation
- Robot creation
- BFS pathfinding
- Robot movement
- Logging

## 10. Future Implementation

The next stage will integrate:

- Linux device driver
- Sensor interface
- System programming
- Inter-process communication
- Testing
