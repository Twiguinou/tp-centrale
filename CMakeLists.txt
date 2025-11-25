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
add_library(tp4_lib STATIC tp4/Date.cpp tp4/Heure.cpp tp4/RDV.cpp)
add_executable(tp4_3 tp4/main3.cpp)
target_link_libraries(tp4_3 tp4_lib)

add_executable(tp5 tp5/main.cpp tp5/Agenda.cpp tp5/NoeudRDV.cpp)
target_include_directories(tp5 PRIVATE tp4)
target_link_libraries(tp5 tp4_lib)

add_library(tp6_lib STATIC tp6/Personne.cpp tp6/Eleve.cpp tp6/Personnel.cpp tp6/PersonnelAdmin.cpp tp6/EnseignantPermanent.cpp tp6/EnseignantVacataire.cpp tp6/ListePersonnel.cpp)
add_executable(tp6_test1 tp6/main_test1.cpp)
target_link_libraries(tp6_test1 tp6_lib)
add_executable(tp6_test2 tp6/main_test2.cpp)
target_link_libraries(tp6_test2 tp6_lib)

add_executable(tp8 tp8/main.cpp tp8/Vector.cpp)

