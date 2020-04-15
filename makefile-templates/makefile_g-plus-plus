CXX = g++ -Werror -Wall

src = $(wildcard *.cpp)
target = $(src:.cpp= )

$(target): $(src)
	$(CXX) -o $@ $^

#03-10_01_Operatoren: $(src)
#	$(CXX) -o $@ $^

#03-10_01_Operatoren_old: 03-10_01_Operatoren.cpp
#	$(CXX) -o $@ $^

#04-04_03_Kontrollstrukturen: 04-04_03_Kontrollstrukturen.cpp
#	$(CXX) -o $@ $^



.PHONY: clean
clean:
	rm -f $(target)
