# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "Adaptive_traffic_control_at_crossroad_autogen"
  "CMakeFiles\\Adaptive_traffic_control_at_crossroad_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Adaptive_traffic_control_at_crossroad_autogen.dir\\ParseCache.txt"
  )
endif()
