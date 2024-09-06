.PHONY: all test s21_string.a clang clean cppcheck rebuild cla cla-i
CC = gcc
FLAGS = -Wall -Wextra -Werror -lm -g -std=c11
FLAGSWNO = -Wall -Wextra -Werror -lm -g -std=c11 -Wno-stringop-truncation 
LINUX=-lsubunit -lrt
LIBS=-lcheck -lm -lpthread
OPEN = firefox
SOURCE=tests/

all: make

make: s21_string.a

test: clean
	make s21_string.a
	$(CC) $(FLAGSWNO) -fprofile-arcs -ftest-coverage s21_string.c tests/*.c s21_string.a -o unit_test $(LIBS) $(LINUX)
	./unit_test

gcov_report: clean
	@make s21_string.a
	@$(CC) $(FLAGSWNO) -fprofile-arcs -ftest-coverage *.c tests/*.c s21_string.a -o unit_test $(LIBS) $(LINUX)
	./unit_test
	lcov -t "unit_test" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN) report/index.html

val: clean
	make s21_string.a
	$(CC) $(FLAGSWNO) -fprofile-arcs -ftest-coverage s21_string.c tests/*.c s21_string.a -o unit_test $(LIBS) $(LINUX)
	valgrind --tool=memcheck --leak-check=yes	./unit_test

s21_string.a: clean
	@$(CC) $(FLAGS) -c *.c
	@ar rcs s21_string.a s21_*.o
	ranlib s21_string.a

cpp: clean
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clean:
	@rm -f *.o $(SOURCE)*.o	@rm -f csh $(SOURCE)csh	@rm -f *.gcno $(SOURCE)*.gcno	@rm -f *.gcov $(SOURCE)*.gcov	@rm -f *.gcda $(SOURCE)*.gcda	@rm -f *.a $(SOURCE)*.a	@rm -f *.info $(SOURCE)*.info	@rm -f *.html $(SOURCE)*.html	@rm -f *.css $(SOURCE)*.css @rm -f s21_*_test $(SOURCE)s21_*_test @rm -f insert_test $(SOURCE)insert_test @rm -f unit_test @rm -f unit_test.c @rm -rf *.gcda @rm -rf *.gcno @rm -rf *.info @rm -rf test @rm -rf report @rm -rf *.dSYM

clean_test:
	@rm -f *.o $(SOURCE)*.o

rebuild:
	make clean
	make

cla:
	clang-format -n *.c *.h
	clang-format -n $(SOURCE)*.c $(SOURCE)*.h

cla-i:
	clang-format -i *.c *.h
	clang-format -i $(SOURCE)*.c $(SOURCE)*.h
