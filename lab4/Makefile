STUDENT_ID=XXXXXXX

TASK1_SRC	:= $(wildcard *.c)
TASK2_SRC 	:= $(wildcard *.c)
EXE		:= qsort func_ptr

all: $(EXE)

task1/qsort: $(TASK1_SRC)
	gcc -Wall -std=c99 -Werror -pedantic -g $^ -o $@

task2/func_ptr: $(TASK2_SRC)
	gcc -Wall -std=c99 -Werror -pedantic -g $^ -o $@

test: task1/qsort
	./$< test1.csv > test1.log
	diff test1.log test1-exp.log

clean:
	rm -f $(EXE)

zip:
	make clean
	mkdir $(STUDENT_ID)-fp-lab
	cp -r  Makefile task1 task2 $(STUDENT_ID)-fp-lab
	zip -r $(STUDENT_ID)-fp-lab.zip $(STUDENT_ID)-fp-lab
	rm -rf $(STUDENT_ID)-fp-lab
