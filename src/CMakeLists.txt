include_guard(GLOBAL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SRCS
)

set(MODULE_NAME "JsonParser")

set(LIBS

)

message(STATUS "libs: ${LIBS}")

if (BUILD_SHARED_LIBS)
    add_library(${MODULE_NAME}_shared SHARED ${SRCS})
    target_link_libraries(${MODULE_NAME}_shared PRIVATE
        ${LIBS}
    )
endif()

if (BUILD_STATIC_LIBS)
    add_library(${MODULE_NAME}_static STATIC ${SRCS})
    target_link_libraries(${MODULE_NAME}_static PRIVATE
        ${LIBS}
    )
endif()
