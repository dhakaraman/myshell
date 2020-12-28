compile: 
	gcc  ls.c -o ls.o
	gcc  rm.c -o rm.o
	gcc  mkdir.c -o mkdir.o 
	gcc  cat.c -o cat.o
	gcc  date.c -o date.o
	gcc  shell.c
	./a.out
	
clean: 
	rm a.out
	rm ls.o
	rm rm.o
	rm mkdir.o
	rm cat.o
	rm date.o
