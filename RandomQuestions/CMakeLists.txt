cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(RandomQuestions)

if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

set(SOURCE main.c)
add_executable(random-questions ${SOURCE})
