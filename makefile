.PHONY: build
build:
	g++ -o build/a.exe src/state.h src/state.cpp src/main.cpp -Wall -Wextra -O2
	