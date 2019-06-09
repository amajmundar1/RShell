cat < src/Or.cpp
wc < src/And.cpp && grep and < And.cpp
grep input < src/Parser.cpp || echo A
cat < integration_tests/pipe_operator_tests.sh | tr a-z A-Z; umask
test -e unit_tests/test.cpp && wc < unit_tests/test.cpp || ls; echo B
exit
