esame.o: esame.cpp
	g++ -c esame.cpp

lib.o: lib.cpp
	g++ -c lib.cpp

esame.x: esame.o	lib.o
	g++ esame.o lib.o -o esame.x

compila: esame.x

esegui: compila
	./esame.x
