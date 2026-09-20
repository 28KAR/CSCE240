compiler = g++
compile = $(compiler) -Wall -c
link = $(compiler) -Wall

all : testToClosestPrime testPrintPrimesBetween testLargestPrimeSequence testPrintAsDollarsAndCents testMakePurchase
	

style : program2functions.cc program2functions.h
	cpplint $^

checkcontainers : check program2functions.h program2functions.cc
	./check program2functions.h
	./check program2functions.cc

check : checkcontainers.cc
	$(compiler) $(flags) $< -o $@

program2functions.o : program2functions.cc program2functions.h checkcontainers
	$(compile) $<

testToClosestPrime.o : testToClosestPrime.cc program2functions.h 
	$(compile) $<

testToClosestPrime : testToClosestPrime.o program2functions.o
	$(link) $^
	./a.out

testPrintPrimesBetweenCall : testPrintPrimesBetweenCall.cc program2functions.o
	$(link) $^ -o $@

testPrintPrimesBetween : testPrintPrimesBetweenOutput.cc testPrintPrimesBetweenCall
	$(link) $<
	./a.out

testLargestPrimeSequence.o : testLargestPrimeSequence.cc program2functions.h
	$(compile) $<

testLargestPrimeSequence : testLargestPrimeSequence.o program2functions.o
	$(link) $^ 
	./a.out

testPrintAsDollarsAndCentsCall : testPrintAsDollarsAndCentsCall.cc program2functions.o
	$(link) $^ -o $@

testPrintAsDollarsAndCents : testPrintAsDollarsAndCentsOutput.cc testPrintAsDollarsAndCentsCall
	$(link) $<
	./a.out

testMakePurchase.o : testMakePurchase.cc program2functions.h
	$(compile) $<

testMakePurchase : testMakePurchase.o program2functions.o
	$(link) $^
	./a.out

clean :
	rm *.o a.out testPrintPrimesBetweenCall testPrintAsDollarsAndCentsCall testMakePurchase student-primes-output.txt student-money-output.txt check

