CXX=g++
INC_DIR = ./include
CXXFLAGS= -c -Wall -I$(INC_DIR)
DEPS = dhtml.h

all: createSlideShow.exe

clean:
		rm -f *.o tests/*.o createSlideShow.exe bin/*.exe obj/*.o

tests: bin/testFileIO.exe bin/testHTML.exe bin/testWriteHTML.exe bin/testReformatString.exe bin/testGenerateHead.exe

bin/testWriteHTML.exe: obj/testWriteHTML.o obj/dhtml.o
	$(CXX) -o testWriteHTML.exe obj/testWriteHTML.o obj/dhtml.o
	mv testWriteHTML.exe bin

bin/testGenerateHead.exe: obj/testGenerateHead.o obj/dhtml.o
	$(CXX) -o testGenerateHead.exe obj/testGenerateHead.o obj/dhtml.o
	mv testGenerateHead.exe bin

bin/testHTML.exe: obj/testHTML.o
	$(CXX) -o testHTML.exe obj/testHTML.o
	mv testHTML.exe bin

bin/testFileIO.exe: obj/testFileIO.o 
	$(CXX) -o testFileIO.exe obj/testFileIO.o
	mv testFileIO.exe bin

bin/testReformatString.exe: obj/testReformatString.o obj/dhtml.o
	$(CXX) -o testReformatString.exe obj/testReformatString.o obj/dhtml.o
	mv testReformatString.exe bin

obj/testReformatString.o: src/testReformatString.cpp 
	$(CXX) $(CXXFLAGS) src/testReformatString.cpp
	mv testReformatString.o obj

obj/testGenerateHead.o: src/testGenerateHead.cpp 
	$(CXX) $(CXXFLAGS) src/testGenerateHead.cpp
	mv testGenerateHead.o obj

obj/testWriteHTML.o: src/testWriteHTML.cpp 
	$(CXX) $(CXXFLAGS) src/testWriteHTML.cpp
	mv testWriteHTML.o obj

obj/dhtml.o: src/dhtml.cpp
	$(CXX) $(CXXFLAGS) src/dhtml.cpp
	mv dhtml.o obj

obj/testFileIO.o: src/testFileIO.cpp
	$(CXX) -c src/testFileIO.cpp
	mv testFileIO.o obj

obj/testHTML.o: src/testHTML.cpp
	$(CXX) -c src/testHTML.cpp
	mv testHTML.o obj
