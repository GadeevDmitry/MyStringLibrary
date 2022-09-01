
all:
	g++ -c src/main.cpp
	g++ -c src/MyString.cpp
	g++ -c src/MyFunc.cpp
	g++ -c src/StringSorter.cpp

	g++ -c TestingSrc/StrncpyTesting.cpp
	g++ -c TestingSrc/StrcatTesting.cpp
	g++ -c TestingSrc/StrchrTesting.cpp
	g++ -c TestingSrc/StrcmpTesting.cpp
	g++ -c TestingSrc/StrcpyTesting.cpp
	g++ -c TestingSrc/StrdupTesting.cpp
	g++ -c TestingSrc/StrlenTesting.cpp
	g++ -c TestingSrc/StrncatTesting.cpp
	g++ -c TestingSrc/FgetsTesting.cpp
	
	g++ StringSorter.o main.o MyString.o MyFunc.o StrncpyTesting.o StrcatTesting.o StrchrTesting.o StrcmpTesting.o StrcpyTesting.o StrdupTesting.o StrlenTesting.o StrncatTesting.o FgetsTesting.o
