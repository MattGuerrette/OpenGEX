
file (GLOB TS_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/TS*)

add_library(${PROJECT_NAME} STATIC
    OpenGEX.h
    OpenGEX.cpp
    ${TS_SOURCE}
)
target_include_directories(${PROJECT_NAME} PUBLIC
    .)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenDDL Microsoft::DirectXMath)
