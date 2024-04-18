CC = gcc
TESTFLAGS_MAC = -lcheck -g
CFLAGS = -Wall -Wextra -Werror -std=c11
TESTFLAGS_LINUX = -lcheck -lm -lpthread -lrt -lsubunit -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: gcov_report install open dist

test: s21_tests.c s21_calc.c s21_stack.c
	$(CC) $(CFLAGS) s21_tests.c s21_calc.c s21_stack.c -o test $(TESTFLAGS_MAC)
	./test

gcov_report:
	$(CC) $(GCOVFLAGS) $(CFLAGS) s21_tests.c s21_calc.c s21_stack.c -o test $(TESTFLAGS_MAC)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno *.dSYM *info
	open report/index.html

rebuild: clean all

clean: 
	rm -rf *.o test *.a a.out *.gcno *.gcda test.dSYM *.info report SmartCalculator ../Archive_SmartCalc_v1.0/

style_check:
	clang-format -style=Google -n *.c *.h *.c

style:
	clang-format -style=Google -i *.c *.h *.c

install:
	mkdir SmartCalculator
	cd SmartCalculator && qmake .. && make && make clean
	
open:
	./SmartCalculator/SmartCalc.app/Contents/MacOS/SmartCalc

uninstall:
	rm -rf SmartCalculator

dvi:
	open ../../README_RUS.md
dist:
	rm -rf ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/
	cp -R ../SmartCalc ../Archive_SmartCalc_v1.0/
	cd ../Archive_SmartCalc_v1.0/ && tar cvzf SmartCalc.tgz *
	cd ../Archive_SmartCalc_v1.0/ && rm -rf SmartCalc
