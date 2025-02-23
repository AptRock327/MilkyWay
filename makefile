.PHONY: clean

milkyWay: $(shell find src -type f -iname '*.cpp')
	g++ -Iinclude -o $@ $^ -lm -lsfml-graphics -lsfml-window -lsfml-system
	
clean:
	rm milkyWay
