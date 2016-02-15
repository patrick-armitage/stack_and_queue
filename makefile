# replace 'your_file' below with your actual source file names.
# add more if needed.

TITLE = stackAndQueue
CXX = Stack.cpp
CXX += Queue.cpp
CXX += main.cpp
DELETE = *.gch
DELETE += *.o

all:
	g++ ${CXX} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
