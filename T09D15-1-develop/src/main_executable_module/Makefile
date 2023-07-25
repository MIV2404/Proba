CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: Quest_3 build_with_static build_with_dynamic

rebuild: clean all

Quest_3: data_process.o data_io.o data_stat.o decision.o main_executable_module.o
	$(CC) data_process.o data_io.o data_stat.o decision.o main_executable_module.o -o ../../build/Quest_3

build_with_static: data_process.o data_io.o data_stat.a decision.o main_executable_module.o    
	$(CC) data_process.o data_io.o decision.o data_stat.a main_executable_module.o -o ../../build/Quest_5

build_with_dynamic: data_process.so data_io.o data_stat.o decision.o main_executable_module.o
	$(CC) data_process.so data_io.o data_stat.o decision.o main_executable_module.o -o ../../build/Quest_6

data_process.o: ../data_module/data_process.c    
	$(CC) $(CFLAGS) ../data_module/data_process.c

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c 
	$(CC) $(CFLAGS) ../data_libs/data_stat.c

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) ../yet_another_decision_module/decision.c

main_executable_module.o: ../main_executable_module/main_executable_module.c
	$(CC) $(CFLAGS) ../main_executable_module/main_executable_module.c

data_stat.a: ../data_libs/data_stat.o
	ar rc data_stat.a ../data_libs/data_stat.o

data_process.so: ../data_module/data_process.o
	gcc -c -fPIC ../data_module/data_process.c -o data_process.o
	gcc -c ../data_libs/data_stat.c
	gcc -shared -o data_process.so data_process.o data_stat.o
	gcc -shared -o ../../build/data_process.so data_process.o data_stat.o

clean:
	rm ../../build/*.so ../../build/Quest* *.o ../data_libs/*.o *.a *.so ../data_module/*.o