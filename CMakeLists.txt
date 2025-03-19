cmake_minimum_required(VERSION 3.28.3)

project(ass1)

# Ativar flags de compilação
set(CMAKE_C_FLAGS "-Wall -Werror -g")

# Incluir diretórios
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Adicionar todos os ficheiros .c
add_executable(ass1
    main.c
    src/myDLL.c
    src/func_aux.c
)