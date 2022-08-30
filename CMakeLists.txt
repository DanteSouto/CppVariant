# CMakeList.txt: projeto de CMake para program, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

project ("program")

# Adicione a origem ao executável deste projeto.
add_executable (program "program.cpp" "program.h" "Util/globais.cpp" "Util/globais.h" "BitConverter/BitConverter.cpp" "BitConverter/BitConverter.h" "Variant/Variant.cpp" "Variant/Variant.h" "Util/stringify.cpp" "Util/stringify.h"     "Util/data.h" "Util/data.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET program PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
