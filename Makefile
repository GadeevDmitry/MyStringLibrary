
all:
#	g++ -c src/main.cpp 	 	-o object/main.o
#	g++ -c src/MyString.cpp  	-o object/MyString.o
#	g++ -c src/MyFunc.cpp    	-o object/MyFunc.o
#	g++ -c src/StringSorter.cpp -o object/StringSorter.o
#	g++ -c src/CommandLine.cpp  -o object/CommandLine.o

#	g++ -c TestingSrc/StrncpyTesting.cpp -o object/StrncpyTesting.o
#	g++ -c TestingSrc/StrcatTesting.cpp  -o object/StrcatTesting.o
#	g++ -c TestingSrc/StrchrTesting.cpp  -o object/StrchrTesting.o
#	g++ -c TestingSrc/StrcmpTesting.cpp  -o object/StrcmpTesting.o
#	g++ -c TestingSrc/StrcpyTesting.cpp  -o object/StrcpyTesting.o
#	g++ -c TestingSrc/StrdupTesting.cpp  -o object/StrdupTesting.o
#	g++ -c TestingSrc/StrlenTesting.cpp  -o object/StrlenTesting.o
#	g++ -c TestingSrc/StrncatTesting.cpp -o object/StrncatTesting.o
#	g++ -c TestingSrc/FgetsTesting.cpp   -o object/FgetsTesting.o

	g++ object/CommandLine.o object/StringSorter.o object/main.o object/MyString.o object/MyFunc.o object/StrncpyTesting.o object/StrcatTesting.o object/StrchrTesting.o object/StrcmpTesting.o object/StrcpyTesting.o object/StrdupTesting.o object/StrlenTesting.o object/StrncatTesting.o object/FgetsTesting.o
