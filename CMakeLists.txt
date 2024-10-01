cmake_minimum_required(VERSION 3.29)
project(Bulls_and_cows)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Bulls_and_cows
    check_input.cpp
    main.cpp
    random_digits.cpp
        user_input.cpp
        loading.cpp
        choose_game.cpp)
