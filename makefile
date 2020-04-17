fish: card_demo.o player.o deck.o card.o
	g++ -o fish card_demo.o player.o deck.o card.o

card_demo.o: card_demo.cpp player.h deck.h card.h
	g++ -c card_demo.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

deck.o: deck.cpp deck.h
	g++ -c deck.cpp

card.o: card.cpp card.h
	g++ -c card.cpp