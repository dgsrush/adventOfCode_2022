package main

import (
	"fmt"
	"os"
	"log"
	"bufio"
	"strconv"
	"sort"
)

func part1() {
	//f, err := os.Open("sample_input.txt")
	f, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
    }

    var cal int = 0
    var maxcal int = 0

	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		if(len(scanner.Text()) > 0) {
			ii, err := strconv.Atoi(scanner.Text())
			if err != nil {
				log.Fatal(err)
		    }
			cal += ii
		} else {
			if(cal > maxcal) {
				maxcal = cal
			}
			cal = 0
		}
	}
	f.Close()

	fmt.Println("GO PART 1 maxcal =", maxcal)
}

func part2() {
	//f, err := os.Open("sample_input.txt")
	f, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
    }

	var cal int = 0
	totals := make([]int, 0)

	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		if(len(scanner.Text()) > 0) {
			ii, err := strconv.Atoi(scanner.Text())
			if err != nil {
				log.Fatal(err)
		    }
			cal += ii
		} else {
			totals = append(totals, cal)
			cal = 0
		}
	}
	f.Close()

	sort.Ints(totals)
	total := totals[len(totals) - 3] + totals[len(totals) - 2] + totals[len(totals) - 1]
	fmt.Println("GO PART 2 total =", total)
}

func main() {
    part1()
	part2()
}
