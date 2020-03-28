CC=gcc
EXEC=Boggle
CFLAGS=-ansi -Wall -pedantic
LDFLAGS=
OBJ=./Main.o ./Arbre.o ./Dictionnaire.o ./Test.o

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

./Main.o: ./include/Arbre.h ./include/Dictionnaire.h ./include/Test.h

./Arbre.o: ./include/Arbre.h

./Dictionnaire.o: ./include/Dictionnaire.h ./include/Arbre.h

./Test.o: ./include/Arbre.h ./include/Dictionnaire.h

./%.o: ./src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f ./*.o

mrproper: clean
	rm -f $(EXEC)

install: $(EXEC)
	mkdir ./bin
	mv $(EXEC) ./bin/
	mv *.o ./bin/
	make mrproper

uninstall: mrproper
	rm -f ./bin/$(EXEC)
	rm -f ./bin/*.o
	rm -rf ./bin

exec: $(EXEC)