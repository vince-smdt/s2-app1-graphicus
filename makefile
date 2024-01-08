all: main clean

main: main.o tests.o canevas.o couche.o vecteur.o forme.o cercle.o carre.o rectangle.o
	g++ -o main main.o tests.o canevas.o couche.o vecteur.o forme.o cercle.o carre.o rectangle.o

main.o: main.cpp tests.h
	g++ main.cpp -g -c

tests.o: tests.cpp tests.h canevas.h cercle.h carre.h
	g++ tests.cpp -g -c

canevas.o: canevas.cpp canevas.h couche.h
	g++ canevas.cpp -g -c

couche.o: couche.cpp couche.h vecteur.h
	g++ couche.cpp -g -c

vecteur.o: vecteur.cpp vecteur.h forme.h
	g++ vecteur.cpp -g -c

forme.o: forme.cpp forme.h coordonnee.h
	g++ forme.cpp -g -c

cercle.o: cercle.cpp cercle.h forme.h
	g++ cercle.cpp -g -c

carre.o: carre.cpp carre.h rectangle.h
	g++ carre.cpp -g -c

rectangle.o: rectangle.cpp rectangle.h forme.h
	g++ rectangle.cpp -g -c

clean:
	rm -f *.o
