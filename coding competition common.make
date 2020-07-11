main: seal_bool.h coding\ competition\ common.h write\ unsigned\ long\ to\ file.c malloc\ with\ error\ checking.c realloc\ with\ error\ checking.c read\ string\ from\ file.c string\ to\ unsigned\ int.c addition\ will\ overflow.c string\ to\ unsigned\ long.c
	gcc -c write\ unsigned\ long\ to\ file.c
	gcc -c malloc\ with\ error\ checking.c
	gcc -c realloc\ with\ error\ checking.c
	gcc -c read\ string\ from\ file.c
	gcc -c string\ to\ unsigned\ int.c
	gcc -c addition\ will\ overflow.c
	gcc -c string\ to\ unsigned\ long.c

clean:
	rm write\ unsigned\ long\ to\ file.o
	rm malloc\ with\ error\ checking.o
	rm realloc\ with\ error\ checking.o
	rm read\ string\ from\ file.o
	rm string\ to\ unsigned\ int.o
	rm addition\ will\ overflow.o
	rm string\ to\ unsigned\ long.o