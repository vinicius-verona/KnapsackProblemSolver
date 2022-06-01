run:
	../bin/main $(ALG) $(SIZE) $(CAP) > ../data/output/n-$(SIZE)x$(CAP)/$(ALG).out

clean:
	find ../bin/ -type f -name '*' -not -name 'README.md' -delete

create-input:
	julia ./InputGenerator/input.jl $(SIZE) $(CAP)

test: clean all
	../bin/main $(ALG) $(SIZE) $(CAP) < ../data/input/n-$(SIZE)x$(CAP)/instance-n-$(SIZE)x$(CAP).in
#> ../data/output/n-$(SIZE)x$(CAP)/$(ALG).out

all: 
	g++ ./main.cpp ./Problem/Problem.cpp ./DPR/RecursiveKnapsack.cpp ./DPI/IterativeKnapsack.cpp ./"B&B"/BranchBoundKnapsack.cpp -o ../bin/main -Wall
# g++ ./main.cpp ./Problem/Problem.cpp ./DPR/RecursiveKnapsack.cpp ./DPI/IterativeKnapsack.cpp -o ../bin/main -Wall