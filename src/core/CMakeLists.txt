set(core_sources
    )


set(core_headers
    Array.h
    Stack.h
    Queue.h
    )

add_library(core INTERFACE)

target_include_directories(core INTERFACE ${CMAKE_SOURCE_DIR}/src/core)

set(core_DEP_LIBS ${CMAKE_DL_LIBS})

target_link_libraries(core ${core_DEP_LIBS})