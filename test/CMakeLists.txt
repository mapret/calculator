cmake_minimum_required(VERSION 3.0.2)

set(test_sources
    main.cpp
)

include_directories(..)
add_executable(${PROJECT_NAME}-test ${test_sources})
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}-lib stdc++fs)
