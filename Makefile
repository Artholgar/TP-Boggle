CC=gcc
EXEC=Boggle
CFLAGS=-ansi -Wall -pedantic
LDFLAGS=
OBJ=./Main.o ./Liste.o ./Dictionnaire.o

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

./Main.o: ./include/Liste.h ./include/Dictionnaire.h

./Liste.o: ./include/Liste.h

./Dictionnaire.o: ./include/Dictionnaire.h ./include/Liste.h

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