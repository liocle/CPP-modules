#!/bin/bash

declare -a tests=(
  "" " " "123 456 789" "\"123456789\""
  "abc" "42abc" "123.45.67" 
  "'👻'" "🤦" "\"42.0\"" "c" 
  "'c'" "'0'"
  "42" "-42" "0" "+42.0" "-42.0" "+0.42" "++42" "--42" "+-42" "-+42" "-0.42" ".42" "-.42" "+.42" 
  "    42" "42      "
  "-0.000001" "0.123456789" 
  "1E3" "2.5e-3" "9.99e+8" "1e-6"
  "2147483647" "-2147483648"
  "2147483648" "-2147483649"
  "1.175494351E-38" "3.402823466E+38"
  "1.175494350E-38" "3.402823467E+38"
  "2.2250738585072014E-308" "1.7976931348623158E+308" 
  "1e400" "1e-400"
  "nan" "+inf" "infiNiTy" "-iNf" "nAnf" "+infF" "-Inff"
)

for test in "${tests[@]}"; do
	 echo
	 echo "Testing with input: \"$test\" $(./convert $test)"
	 echo "________________________________________________________________________________"
done
