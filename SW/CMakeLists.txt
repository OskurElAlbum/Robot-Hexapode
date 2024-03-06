cmake_minimum_required( VERSION 2.15 )

project (Cible_µc)

set(SOURCE src/hello.c)

add_library(toto ${SOURCE})

add_executable (Cible_µc src/main.c)
# add_executable (Hello apps/main.c)
target_link_libraries(Cible_µc toto)