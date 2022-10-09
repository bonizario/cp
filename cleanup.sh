cd problems
find . -type f -not \( -name '*.c' -or -name '*.cpp' -or -name '*.py' -or -name '*.sql' -or -name '*.exs' -or -name '*.txt' -or -name '*.sh' -or -name '*.md' \) -delete
cd ..
