CC = gcc
CFLAGS = -Iheaders

objects = main.o menu.o execVm.o checkFile.o

qemuS: $(objects)
	$(CC) $^ -o qemuS

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

menu.o: functions/menu.c
	$(CC) $(CFLAGS) -c functions/menu.c -o menu.o

execVm.o: functions/execVm.c
	$(CC) $(CFLAGS) -c functions/execVm.c -o execVm.o

checkFile.o: functions/checkFile.c
	$(CC) $(CFLAGS) -c functions/checkFile.c -o checkFile.o

clean:
	rm -f *.o qemuS
