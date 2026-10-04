savedcmd_warehouse_sensor.mod := printf '%s\n'   warehouse_sensor.o | awk '!x[$$0]++ { print("./"$$0) }' > warehouse_sensor.mod
