 #!/usr/bin/bash
echo "g++ -Wall -std=c++11 -lpthread board.cpp core_simulation.cpp box.cpp mydevices.cpp maison.cpp piece.cpp sketch_ino.cpp -o arduino"
g++ -Wall -std=c++11 -pthread ./src/board.cpp ./src/core_simulation.cpp ./src/box.cpp ./src/mydevices.cpp ./src/maison.cpp ./src/piece.cpp ./src/sketch_ino.cpp -o arduino
