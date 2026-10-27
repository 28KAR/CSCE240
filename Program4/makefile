compiler = g++
flags = -std=c++17 -Wall 

style : height.cc height.h p4functions.cc p4.cc
	cpplint $^

height.o : height.cc height.h
	$(compiler) $(flags) -c $< 

testheight1 : testheight1.cc height.o
	$(compiler) $(flags) $^
	./a.out

testheight2 : testheight2.cc height.o
	$(compiler) $(flags) $^
	./a.out

testheight3 : testheight3.cc height.o
	$(compiler) $(flags) $^
	./a.out

testheight4 : testheight4.cc height.o
	$(compiler) $(flags) $^
	./a.out

p4functions.o : p4functions.cc p4functions.h
	$(compiler) $(flags) -c $<

testsort : testsortheights.cc p4functions.o height.o
	$(compiler) $(flags) $^
	./a.out

checkit : checkit.cc
	$(compiler) $(flags) $< -o checkit

p4.o : p4.cc p4functions.h height.h checkit
	$(compiler) $(flags) -c $<

p4test1 : p4.o height.o p4functions.o
	$(compiler) $(flags) $^
	./a.out < test-input1.txt > student-output1.txt
	./checkit 0

p4gdb : p4.cc p4functions.cc height.cc
	$(compiler) $(flags) -g $^ -o $@

leakcheck: p4gdb
	valgrind --leak-check=full ./p4gdb < test-input1.txt > student-output1.txt

clean :
	rm  *.o a.out student-output*.txt p4gdb checkit

