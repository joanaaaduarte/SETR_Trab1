cmake_minimum_required(VERSION 3.30.5)

project(ass1)

# Ativar flags de compilação
set(CMAKE_C_FLAGS "-Wall -Werror -g")

# Incluir diretórios
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src/group/myDLL)
include_directories(${CMAKE_SOURCE_DIR}/src/group/aux)

# Adicionar todos os ficheiros .c
add_executable(ass1
    src/main.c
    src/group/myDLL/myDLL_find.c
    src/group/myDLL/myDLL_init.c
    src/group/myDLL/myDLL_insert.c
    src/group/myDLL/myDLL_remove.c
    src/group/aux/func_aux.c
)