#!/usr/bin/env bash
g++ -std=c++23 -O2 marketmaking.cpp -o test || exit 1

pass=0; fail=0
run() {
  local name="$1" input="$2" expected="$3"
  local actual
  actual=$(./test <<< "$input")
  if [[ "$actual" == "$expected" ]]; then
    echo "PASS $name"; pass=$((pass+1))
  else
    echo "FAIL $name"
    diff <(echo "$expected") <(echo "$actual")
    fail=$((fail+1))
  fi
}

run "1: example" "3 6 5
QUOTE
FILL S 12
QUOTE
FILL S 12
REVEAL 6
QUOTE
FILL S 14
REVEAL 5
QUOTE
FILL B 15
SETTLE 15" "9 12
9.5 12.5
12.7 15.3
15.1 16.9
-7"

run "2: long limit" "2 6 2
QUOTE
FILL B 6
QUOTE
FILL B 6.5
QUOTE
FILL S 8
SETTLE 9" "5.7 8.3
5.2 7.8
- 7.3
4.5"

run "3: short limit" "1 6 1
QUOTE
FILL S 4
QUOTE
SETTLE 2" "2.6 4.4
3.1 -
2"

run "4: d20 + zero SD" "1 20 3
QUOTE
REVEAL 17
QUOTE
FILL S 17.5
SETTLE 17" "7.6 13.4
16.5 17.5
0.5"

echo "$pass passed, $fail failed"
