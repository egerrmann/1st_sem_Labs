set(HEADER_FILES Student.h StudentAfter1stSession.h StudentAfter2ndSession.h)
set(SOURCE_FILES Student.cpp StudentAfter1stSession.cpp StudentAfter2ndSession.cpp)

add_library(src ${HEADER_FILES} ${SOURCE_FILES})