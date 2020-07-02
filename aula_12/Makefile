#Make file para gerar o programa
PREFIXOS = -I include -std=c++11 -Wall

diary: App.o Data.o Diario.o Funcs.o main.o Time.o
	g++ $(PREFIXOS) -o diary App.o Data.o Diario.o Funcs.o main.o Time.o

main.o: src/main.cpp
	g++ $(PREFIXOS) -c src/main.cpp

App.o: src/App.cpp
	g++ $(PREFIXOS) -c src/App.cpp

Data.o: src/Data.cpp
	g++ $(PREFIXOS) -c src/Data.cpp

Diario.o: src/Diario.cpp
	g++ $(PREFIXOS) -c src/Diario.cpp

Funcs.o: src/Funcs.cpp
	g++ $(PREFIXOS) -c src/Funcs.cpp

Time.o: src/Time.cpp
	g++ $(PREFIXOS) -c src/Time.cpp