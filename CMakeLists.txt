cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 20)				
								

project(hello_world)			# Название проекта

set(SOURCE_EXE 
	"src/calculatormodel.cpp"
	"src/error.cpp"
	"src/var_resolver.cpp"
)		# Установка переменной со списком исходников для исполняемого файла

#set(SOURCE_LIB foo.cpp)			# Тоже самое, но для библиотеки

#add_library(foo STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(calc ${SOURCE_EXE} "src/main.cpp")	# Создает исполняемый файл с именем main
target_include_directories(calc PRIVATE thirdparty/cli11)

#target_link_libraries(main foo)		# Линковка программы с библиотекой