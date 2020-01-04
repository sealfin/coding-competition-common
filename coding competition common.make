main: seal_bool.h coding\ competition\ common.h malloc\ with\ error\ checking.c realloc\ with\ error\ checking.c read\ string\ from\ file.c string\ to\ unsigned\ int.c
	gcc -c malloc\ with\ error\ checking.c
	gcc -c realloc\ with\ error\ checking.c
	gcc -c read\ string\ from\ file.c
	gcc -c string\ to\ unsigned\ int.c

clean:
	rm malloc\ with\ error\ checking.o
	rm realloc\ with\ error\ checking.o
	rm read\ string\ from\ file.o
	rm string\ to\ unsigned\ int.o