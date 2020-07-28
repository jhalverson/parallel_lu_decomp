CXX=mpicxx
CXXFLAGS=-Ofast -xHost
#CXXFLAGS=-Ofast -march=native
CPPFLAGS=-I/usr/include
LDFLAGS=-L/lib64
LDLIBS=-lgsl -lgslcblas

lu: lu.o
	$(CXX) $(CXXFLAGS) -o lu lu.o $(LDFLAGS) $(LDLIBS)

lu.o: lu.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c lu.cpp

clean:
	rm -f lu.o lu
