# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PowerShell-Email-Generator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PowerShell-Email-Generator_autogen.dir/ParseCache.txt"
  "PowerShell-Email-Generator_autogen"
  )
endif()
