# Используемый компилятор
CC = gcc
# Флаги компиляции, могут быть отличны в разных комп. и сист.
FLAGS = -Wall -Werror -Wextra -pedantic -Ofast -std=c11
# Явное указание игнорировать файлы с указанными именами в папке
.PHONY: all clean rebuild uninstall
# Общая сборка по умолчанию
all: make

make: s21_cat
# Сборка по зависимостям, позволяет собрать новый общий файл 
s21_cat: s21_cat_input.o s21_cat_print.o s21_cat_.o global.h
	$(CC) $(FLAGS) s21_cat_.o s21_cat_input.o s21_cat_print.o -o s21_cat
#Сборка пофункционально
s21_cat_input.o: s21_cat_input.c global.h
	$(CC) $(FLAGS) -c s21_cat_input.c -o s21_cat_input.o
s21_cat_print.o: s21_cat_print.c global.h
	$(CC) $(FLAGS) -c s21_cat_print.c -o s21_cat_print.o
s21_cat_.o: s21_cat.c global.h
	$(CC) $(FLAGS) -c s21_cat.c -o s21_cat_.o
# запуск теста результатов cat:
test_cat:
	bash testCat.sh
valgrind: s21_cat
	valgrind --tool=memcheck --leak-check=yes  ./s21_cat -n test_files/test.txt
# очистка в каталогах:
clean:
	rm -rf *.o *.out *.exe s21_cat s21_cat.txt cat.txt log.txt *.sh
# очистка и компиляция заново:
rebuild: clean all



