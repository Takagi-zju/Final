all: src/julia.cpp src/bitmap.cpp
	g++ -o bin/juliaset src/julia.cpp src/bitmap.cpp -std=c++11
report:
	xelatex report.tex
	bibtex report.aux
	xelatex report.tex
	xelatex report.tex
