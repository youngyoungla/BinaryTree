floor_print:floor_print.c
	g++ -o $@ $^
.PHONY:
clean:
	rm -f floor_print
