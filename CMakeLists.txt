cmake_minimum_required(VERSION 3.10)
project(kime C)

set(CMAKE_C_STANDARD 99)

add_executable(kime kime.c option.c log.c http.c mod_static.c dict.c murmurhash2.c http_server.c ioloop.c)