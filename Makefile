all: julia.cpp bitmap.cpp
	g++ -o juliaset julia.cpp bitmap.cpp -std=c++11
