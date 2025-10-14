cmake_minimum_required(VERSION 3.25)

project(TP C CXX)

add_executable(tp1_1 tp1/main1.c)
add_executable(tp1_2 tp1/main2.c)
add_executable(tp1_3 tp1/main3.c)

add_executable(tp2_1 tp2/main1.cpp tp2/Point.cpp)
add_executable(tp2_2 tp2/main2.cpp tp2/Vector.cpp)
add_executable(tp2_3 tp2/main3.cpp tp2/ArrayOfInteger.cpp)

add_executable(tp4_1 tp4/main1.cpp tp4/Date.cpp)
add_executable(tp4_2 tp4/main2.cpp tp4/Heure.cpp)
add_executable(tp4_3 tp4/main3.cpp tp4/Date.cpp tp4/Heure.cpp tp4/RDV.cpp)

