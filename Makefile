CXX = g++
RM=rm -f

EXTRA_CCFLAGS   = -Wall -Wextra -Wcast-qual -Wfloat-equal -Wpedantic -Wpointer-arith -Wshadow
CXXOPTFLAGS     = -O2
CXXFLAGS        = -std=c++11 $(EXTRA_CCFLAGS) $(CXXOPTFLAGS)

LDLIBS=-larmadillo

TARGET = test
SOURCE_FILES=src/process.cpp src/AudioFile.cpp src/utils.cpp src/effects.cpp
OBJECT_FILES=$(subst .cpp,.o,$(SOURCE_FILES))

all: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECT_FILES) $(LDLIBS)

depend: .depend

.depend: $(SOURCE_FILES)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJECT_FILES)

include .depend


# g++ -std=c++11 test.cpp -L$HOME/Dropbox/University/cpp/arma-dsp/ -ladsp -larmadillo -o test 