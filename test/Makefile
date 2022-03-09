#make  - to compile normal run
#make test - to compile for unit testing 
### declare directory
GTEST_DIR=/opt/src/googletest/googletest
SRC_DIR=source
TCASE_DIR=test_case
INC_DIR=include

###	declare variable
PROJ=string
TCASE := $(or $(TCASE_DIR)/*.c, $(TCASE_DIR)/*.cpp)
DEPS= $(INC_DIR)/my_string.h

### FLAGS
COPTS=-Wall -funsigned-char -fpermissive -fprofile-arcs -ftest-coverage 
LDFLAGS=-lm -lgcov --coverage 
CXXFLAGS= -isystem $(GTEST_DIR)/include -I$(GTEST_DIR)  


######### Main targets ##########
release: main.o $(SRC_DIR)/$(PROJ).o
	$(CC) $^ -o $@ $(LDFLAGS)

#### We need -pthread as Google Test uses thread
#### Build a test depends on test_case foldler #####
.PHONY:test 
test: string_test_case.o $(PROJ)_test.o libgtest.a 
	$(CXX)  $(LDFLAGS) $(CXXFLAGS) -pthread $^ -o my_test.exe

########## Normal - Release ###########
*.o: $(SRC_DIR)/*.c
	$(CC) -c $<

########## Unit test - test ########
$(PROJ)_test.o: $(SRC_DIR)/$(PROJ).c $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -I$(INC_DIR) -o $@

string_test_case.o: $(TCASE) $(DEPS)
	$(CXX)  $(CXXFLAGS) -c $< -I$(INC_DIR) -I-$(COPTS) 

########## Google Test framework ############
#For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o: ${GTEST_DIR}/src/gtest-all.cc 
	$(CXX) -pthread $(CXXFLAGS) -c $< 
gtest_main.o: gtest_main.cc
	$(CXX) $(CXXFLAGS) -c $<
libgtest.a: gtest-all.o gtest_main.o
	$(AR) -rv libgtest.a gtest-all.o gtest_main.o

########## Clean ######################
clean:
	rm -f *.o my_test.exe

