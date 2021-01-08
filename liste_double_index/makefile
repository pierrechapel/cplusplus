CXX=g++
CXXFLAGS=-Wall -ggdb
RM=rm -f

test-addback: test-addback.o
	$(CXX) $(CXXFLAGS) -o $@ $<
	
test-addback.o: test-addback.cpp intlist.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	
test-addfront: test-addfront.o
	$(CXX) $(CXXFLAGS) -o $@ $<
	
test-addfront.o: test-addfront.cpp intlist.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	
test-removeback: test-removeback.o
	$(CXX) $(CXXFLAGS) -o $@ $<
	
test-removeback.o: test-removeback.cpp intlist.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	
test-removefront: test-removefront.o
	$(CXX) $(CXXFLAGS) -o $@ $<
	
test-removefront.o: test-removefront.cpp intlist.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	
clean: 
	$(RM) test-addback test-addback.o test-addfront test-addfront.o test-removeback test-removeback.o test-removefront test-removefront.o