thjalfi_test: src/main.cpp src/util.cpp src/board.cpp src/position.cpp src/moves/move.cpp src/moves/movegen.cpp src/defs.cpp
	g++ src/main.cpp src/util.cpp src/board.cpp src/position.cpp src/moves/move.cpp src/moves/movegen.cpp src/defs.cpp -o thjalfi_test

uci_test: src/util.cpp src/board.cpp src/position.cpp src/uci.cpp
	g++ src/uci.cpp src/util.cpp src/board.cpp src/position.cpp -o uci_test

thjalfi_test_mac: src/main.cpp src/util.cpp src/board.cpp src/position.cpp src/moves/move.cpp src/moves/movegen.cpp
	clang++ -std=c++11 -stdlib=libc++ src/main.cpp src/util.cpp src/board.cpp src/position.cpp src/moves/move.cpp src/moves/movegen.cpp -o thjalfi_test