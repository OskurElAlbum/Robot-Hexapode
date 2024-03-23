cmake_minimum_required(VERSION 3.20)

project(Hexapi)

set(CMAKE_CXX_STANDARD 11)

# Ajoutez ici vos fichiers source
set(SOURCES main/Src/main.cpp)

# Définissez ici les bibliothèques nécessaires
set(LIBRARIES wiringPi)

# Spécifiez la toolchain pour Raspberry Pi
set(CMAKE_TOOLCHAIN_FILE "/cmake/PI4B_toolchain.cmake")

# Créez l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Liez les bibliothèques
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})