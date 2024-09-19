CC = g++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++17
TESTFLAGS = -lgtest -pthread -lstdc++ -lrt -lpthread -lm
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: install

tests: s21_test.cc model/*.cc

rebuild: clean all

clean:
	rm -rf *.o test *.a a.out *.gcno *.gcda test.dSYM *.info report SmartCalculator ../dist test

style:
	find . -type f \( -name "*.cc" -o -name "*.cpp" -o -name "*.h" \) -print0 | xargs -0 clang-format -style=Google -n

open:
	SmartCalculator/Calculator

install:
	mkdir -p SmartCalculator
	cd SmartCalculator && qmake .. && make

uninstall:
	rm -rf SmartCalculator

dvi:
	open ../../README_RUS.md

dist:
	mkdir -p ../dist
	cp -R * ../dist
	cd ../dist && tar cvzf Calculator.tgz *
	cd ../dist && rm -rf *.cc *.cpp *.h *.ui calc* Calculator Makefile controller model view *.pro *.pro.user

gcov_report:
	$(CC) $(GCOVFLAGS) $(CFLAGS) s21_test.cc model/model.cc model/token.cc -o test $(TESTFLAGS)
	./test
	lcov -t "test" -o test.info -c -d . --exclude '*/usr/*' --exclude '*/12/*'
	genhtml -o report test.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno *.dSYM *info
	open report/index.html
