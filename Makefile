CFLAGS = -std=c++11 -Wall 
CC = g++

all: build

build: collegemain.o course.o college.o
		$(CC) $(CFLAGS) collegemain.o course.o college.o -o all

collegemain: collegemain.o course.o college.o
		$(CC) $(CFLAGS) collegemain.o course.o college.o -o all

course.o: course.cc course.h
	$(CC) $(CFLAGS) course.cc

college.o: college.cc college.h course.cc course.h
	$(CC) $(CFLAGS) college.cc

collegemain.o: collegemain.cc course.h college.h
	$(CC) $(CFLAGS) collegemain.cc

test: build runtest

runtest: test_college
	./test_college

test_college.o: test_college.cc
		$(CC) $(CFLAGS) test_college.cc -c

test_college: college.o test_college.o course.o
	$(CC) -o test_college test_college.o college.o course.o

clean:
	rm -f *.o collegemain test_college
