cmake_minimum_required(VERSION 4.4.4)

project(kernel_dust)

set(CMAKE_C_FLAGS -ffreestanding -O2 -Wall 
-Wextra -Werror -Wno-unused-parameter
-fno-stack-protector -fno-pie -fno-pic
-mno-red-zone -mno-mmx -mno-sse -mno-sse2 -mno-avx
-nostdlib)

