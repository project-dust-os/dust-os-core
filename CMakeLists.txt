cmake_minimum_required(VERSION 4.4.4)

project(Dust-os LANGUAGE C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS -ffreestanding -O2 -Wall 
-Wextra -Werror -Wno-unused-parameter
-fno-stack-protector -fno-pie -fno-pic
-mno-red-zone -mno-mmx -mno-sse -mno-sse2 -mno-avx
-nostdlib) 
