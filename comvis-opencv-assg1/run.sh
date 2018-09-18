mkdir bin
g++ -std=c++11 lab05.cpp -o bin/lab05 `pkg-config --cflags --libs opencv`
./bin/lab05
