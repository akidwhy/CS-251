all: sq.o sq.o llist.o driver fdriver

ll_tst: llist.o ll_tst.c
	gcc ll_tst.c llist.o -o ll_tst

llist.o:  list.h llist.c
	gcc -c llist.c

sq.o: llist.o sq.h sq.c
	gcc -c sq.c
	
driver: driver.c sq.o 
	gcc driver.c sq.o llist.o -lc -o driver

fdriver: driver.c sq.o 
	gcc fdriver.c sq.o llist.o -lc -o fdriver