set(HEADER_FILES calculator.h stack.h)
set(SOURCE_FILES calculator.cpp Stack.cpp)

add_library(src ${HEADER_FILES} ${SOURCE_FILES})