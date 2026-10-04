# Stage 4 – Initial Implementation & Prototype

## Implemented Modules

### 1. Warehouse Module
Responsible for:
- Grid creation
- Obstacle management
- Grid validation
- Warehouse display

### 2. Robot Module
Responsible for:
- Robot position
- Robot movement

### 3. PathFinder Module
Responsible for:
- BFS pathfinding
- Obstacle avoidance
- Route generation

### 4. Linux Device Driver
Responsible for:
- Creating virtual sensor device
- Receiving sensor information
- Returning sensor information through ioctl

### 5. IPC Module
The application uses pipe() and fork() for communication between the robot controller and monitoring process.

### 6. Logging
The system records major events in a log file.

## Prototype Result

The initial prototype successfully:
- Creates warehouse
- Places obstacles
- Finds a path
- Moves robot
- Communicates with device driver
- Displays sensor information
- Sends robot position to monitoring process
