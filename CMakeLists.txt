cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 20)				
								

project(hello_world)			# �������� �������

set(SOURCE_EXE 
	"src/calculatormodel.cpp"
	"src/error.cpp"
	"src/var_resolver.cpp"
)		# ��������� ���������� �� ������� ���������� ��� ������������ �����

#set(SOURCE_LIB foo.cpp)			# ���� �����, �� ��� ����������

#add_library(foo STATIC ${SOURCE_LIB})	# �������� ����������� ���������� � ������ foo

add_executable(calc ${SOURCE_EXE} "src/main.cpp")	# ������� ����������� ���� � ������ main
target_include_directories(calc PRIVATE thirdparty/cli11)

#target_link_libraries(main foo)		# �������� ��������� � �����������