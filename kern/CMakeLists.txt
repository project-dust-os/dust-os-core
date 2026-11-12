cmake_minimum_required(VERSION 4.4.4)

project(kernel-org)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS -ffrestanding -m64 -nostdlib -nostdint -O3 -Wall -Wextra
-fno-builtin -fno-stack-protector -mno-red-zone -mcmodel=kernel)

