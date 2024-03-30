#!/bin/bash

GREEN="\e[0;32m"
RED="\e[0;31m"
BLACK="\e[0;30m"
YELLOW="\e[1;33m"
BLUE="\e[0;34m"
PURPLE="\e[1;95m"
BG_PURPLE="\e[45m"
END="\e[0m"

RE=0
N_TESTS=1000
PASSED_TEST=0
INSTRUCTIONS=0
BEST_CASE=1000000000000000
WORST_CASE=0
NUM_ARR=$(seq -1000 1000) 
if [ "$#" == "0" ]; then printf "Usage: ./tester <number qty> <loop times>. If no loop times are provided, it will default to 1000.\n"; exit 1; fi
if [ -n "$2" ]; then N_TESTS=$2; fi
printf "\033c"
printf "\t${YELLOW}TESTING $1 NUMBERS ${END}\n\n"
for ((i=1 ; i<=N_TESTS ; i++)); do
	ARG="$(shuf -n $1 <<< $NUM_ARR | tr "\n" " ")"
	NLINES=$(./push_swap $ARG | wc -l) 
	PASS=$(./push_swap $ARG | ./checker_linux $ARG)
	printf "$i.\tInstructions: $NLINES"
	if [ "$PASS" == "OK" ]; then
		RE=$GREEN
		PASSED_TEST=$((PASSED_TEST+1))
		INSTRUCTIONS=$(( $INSTRUCTIONS + $NLINES ))
		if [ $NLINES -gt $WORST_CASE ]; then WORST_CASE=$NLINES; fi
		if [ $NLINES -lt $BEST_CASE ]; then BEST_CASE=$NLINES; fi
	else
		RE=$RED
		PASS="KO"
	fi
	printf "${RE} \t[$PASS]${END}\n"
done

printf "\n\t${PURPLE}STATS FOR $1 NUMBERS${END}\n"
printf "\nPASSED TESTS \t\t$PASSED_TEST out of $N_TESTS\n"
printf "AVERAGE INSTRUCTIONS\t$(($INSTRUCTIONS / $PASSED_TEST))\n"
printf "BEST CASE EVALUATED\t$BEST_CASE\n"
printf "WORST CASE EVALUATED\t$WORST_CASE\n"