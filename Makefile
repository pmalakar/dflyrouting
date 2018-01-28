CC=cc
CXX=CC

CFLAGS= -std=c++11 -O3 -g -DDEBUG
#LIBS=-L./ -lariesroute 

SRCS = route.cxx \
       path.cxx 

OBJS = 	$(SRCS:.cxx=.o)

TARGET = path

all:    $(TARGET)
		@echo Compilation done.

%.o:%.cxx
		$(CXX) $(CFLAGS) $(LIBS) -c $< -o $@

$(TARGET): $(OBJS) 
		$(CXX) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

clean:
		$(RM) *.o *~ $(MAIN) $(TARGET)

