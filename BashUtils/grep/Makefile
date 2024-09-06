# Используемый компилятор
CC = gcc
# Флаги компиляции, могут быть отличны в разных комп. и сист.
FLAGS = -Wall -Werror -Wextra -pedantic -Ofast -std=c11
# Пути компиляции для библиотек и файлов
# Явное указание игнорировать файлы с указанными именами в папке
.PHONY: all clean rebuild uninstall
# Общая сборка по умолчанию
all: make
make: s21_grep
# Сборка по зависимостям, позволяет собрать новый общий файл 
s21_grep: s21_grep_in.o s21_grep_insp.o s21_grep_out.o global.h
	$(CC) $(FLAGS) s21_grep_in.o s21_grep_insp.o s21_grep_out.o -o s21_grep
#Сборка пофункционально
s21_grep_in.o: s21_grep_in.c global.h
	$(CC) $(FLAGS) -c s21_grep_in.c -o s21_grep_in.o
s21_grep_insp.o: s21_grep_insp.c global.h
	$(CC) $(FLAGS) -c s21_grep_insp.c -o s21_grep_insp.o
s21_grep_out.o: s21_grep_out.c global.h
	$(CC) $(FLAGS) -c s21_grep_out.c -o s21_grep_out.o
# запуск теста результатов grep:
testgrep:
	bash test_rep.sh
# запуск теста clang-format:
valgrind: s21_grep
	valgrind --tool=memcheck --leak-check=yes  ./s21_grep -f patterns.txt test_files/test.txt
# очистка в каталогах:
clean:
	rm -rf *.o *.out *.exe s21_grep s21_grep.txt test.txt grep.txt log.txt log1.txt *.sh
# очистка и компиляция заново:
rebuild: clean all
