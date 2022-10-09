# ~/.zshrc
# alias c="code ~/Projects/cp && exit"
# alias f="cd ~/Projects/cp && source cleanup.sh && find problems -type f | wc -l"
cd problems
find . -type f -not \( -name '*.c' -or -name '*.cpp' -or -name '*.py' -or -name '*.sql' -or -name '*.exs' -or -name '*.txt' -or -name '*.sh' -or -name '*.md' \) -delete
find . -type f \( -name '1.py' \) -delete
cd ..
