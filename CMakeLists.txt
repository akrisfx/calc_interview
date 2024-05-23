cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 20)
								
								

project(hello_world)			# Название проекта

set(SOURCE_EXE 
	calculatormodel.cpp
	error.cpp
)		# Установка переменной со списком исходников для исполняемого файла

#set(SOURCE_LIB foo.cpp)			# Тоже самое, но для библиотеки

#add_library(foo STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(main ${SOURCE_EXE} "main.cpp")	# Создает исполняемый файл с именем main

#target_link_libraries(main foo)		# Линковка программы с библиотекой