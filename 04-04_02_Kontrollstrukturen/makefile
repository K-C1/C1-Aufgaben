CXX = gcc -Werror -Wall

src = $(wildcard *.cpp)
target = $(src:.cpp= )

libs = -lstdc++ -lm

$(target): $(src)
	$(CXX) -o $@ $^ $(libs)
 
.PHONY: clean
clean:
	rm -f $(target)
