set(TARGET_NAME "Database")
add_library(${TARGET_NAME} "")
include(FetchContent)
target_sources(${TARGET_NAME}
PRIVATE
    abstract_table.cpp
    database.cpp
    documentation_table.cpp
    mtv_table.cpp
    sql_commands.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/abstract_table.hpp
        ${CMAKE_CURRENT_LIST_DIR}/database.hpp
        ${CMAKE_CURRENT_LIST_DIR}/documentation_table.hpp
        ${CMAKE_CURRENT_LIST_DIR}/mtv_table.hpp
        ${CMAKE_CURRENT_LIST_DIR}/sql_commands.hpp
)




target_link_libraries(${TARGET_NAME} PRIVATE fmt::fmt  -lpqxx)

target_include_directories(${TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_SOURCE_DIR}/src/libUtilities
)



target_compile_options(${TARGET_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wconversion
        -Wsign-conversion
)
