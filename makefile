thjalfi_test: src/main.cpp src/util.cpp src/board.cpp src/position.cpp
	g++ src/main.cpp src/util.cpp src/board.cpp src/position.cpp -o thjalfi_test

uci_test: src/util.cpp src/board.cpp src/position.cpp src/uci.cpp
	g++ src/uci.cpp src/util.cpp src/board.cpp src/position.cpp -o uci_test