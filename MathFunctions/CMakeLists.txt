#first we add the executable that generates the table
add_executable(MakeTable MakeTable.cxx)

#add the command to geenrate the source code
#we add a custom command that specifies how to produce Table.h by running MakeTable
add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	DEPENDS MakeTable

)

#add the binary tree directory to the search path for
#include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR})

add_library(MathFunctions STATIC mysqrt.cxx
	${CMAKE_CURRENT_BINARY_DIR}/Table.h)



#For the MathFunctions libraray we setup the libraray and the header file to be installed by adding the following two lines
install (TARGETS MathFunctions DESTINATION "${PROJECT_BINARY_DIR}/MathFunctions/bin")
install (FILES MathFunctions.h DESTINATION "${PROJECT_BINARY_DIR}/MathFunctions/include")
