static: seal_bool.h coding\ competition\ common.h write\ unsigned\ long\ to\ file.c malloc\ with\ error\ checking.c realloc\ with\ error\ checking.c read\ string\ from\ file.c string\ to\ unsigned\ int.c addition\ will\ overflow.c string\ to\ unsigned\ long.c
	gcc -c *.c
	-[ -f coding\ competition\ common.a ] && rm coding\ competition\ common.a # Yes, I'm aware that `-rm coding\ competition\ common.a` would be shorter.
	ar -cq coding\ competition\ common.a *.o
	rm *.o

static_PowerPC: static
	-[ -f coding\ competition\ common.PPC.a ] && rm coding\ competition\ common.PPC.a # Yes, I'm aware that `-rm coding\ competition\ common.PPC.a` would be shorter.
	mv coding\ competition\ common.a coding\ competition\ common.PPC.a
