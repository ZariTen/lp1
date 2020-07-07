PREFIXOS = -I include -std=c++11 -Wall

program: conta.o main.o agencia.o cliente.o
	g++ $(PREFIXOS) -o program conta.o main.o agencia.o cliente.o

main.o: src/main.cpp
	g++ $(PREFIXOS) -c src/main.cpp

conta.o: src/conta.cpp
	g++ $(PREFIXOS) -c src/conta.cpp

agencia.o: src/agencia.cpp
	g++ $(PREFIXOS) -c src/agencia.cpp

cliente.o : src/cliente.cpp
	g++ $(PREFIXOS) -c src/cliente.cpp

clean:
	rm -f *.o