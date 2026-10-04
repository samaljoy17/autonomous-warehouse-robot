# Stage 5 – Testing, Integration & Improvement

## Unit Testing

The following components were tested:

- Warehouse validation
- Obstacle detection
- BFS pathfinding
- Unreachable destination detection

## Integration Testing

The following integration was tested:

C++ Application
        ↓
Linux Device
        ↓
Kernel Driver
        ↓
Sensor Data

## System Testing

The complete application was executed on Linux.

## Test Cases

| Test | Expected Result | Status |
|------|-----------------|--------|
| Empty warehouse | Path found | PASS |
| Obstacles | Robot avoids obstacles | PASS |
| Blocked destination | No path | PASS |
| Device driver | Sensor communication | PASS |
| IPC | Monitor receives position | PASS |

## Improvements

- Modular C++ architecture
- Error handling
- Logging
- Device-driver interface
- Unit tests
