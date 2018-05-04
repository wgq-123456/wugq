#LIBS = -lnnxx
#CXXFLAGS = -g  -Werror -Wall -std=c++11 -I../include -I../common
CXXFLAGS = -fpic -shared -g -Wall -std=c++11 -I../inc
TARGET = libspfw.so

OBJECTS =  jsoncpp.o  utils.o 
SOURCES = jsoncpp.cpp utils.cpp 


#%.o: %.c
#	$(CXX) -c $(CXXFLAGS)  $< -o $@ 

#%.d: %.c
#	@set -e; rm -f $@; /
#	$(CXX) -MM  $(CXXFLAGS)   $< > $@.$$$$; /
#	sed 's,/($*/)/.o[ :]*,/1.o $@ : ,g' < $@.$$$$ > $@; /
#	rm -f $@.$$$$


all: $(TARGET) CMD

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o  $(TARGET)  $(OBJECTS) 

jsoncpp.o : jsoncpp.cpp 
	$(CXX) $(CXXFLAGS) -c $< 


utils.o :utils.cpp 
	$(CXX) $(CXXFLAGS) -c $< 

CMD:
	cp ./libspfw.so  ../output/


#centre.o : ../common/centre.cpp 
#	$(CXX) $(CXXFLAGS) -c $< 


.PHONY :clean
clean:
	-$(RM) $(TARGET) $(OBJECTS)
	rm -rf ../output/libspfw.so

