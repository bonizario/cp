# ~/.zshrc
# alias c="code ~/projects/cp && exit"
# alias f="cd ~/projects/cp && source utils/cleanup.sh && find problems -type f | wc -l"
cd problems
find . -type f -not \( -name '*.c' -or -name '*.cpp' -or -name '*.py' -or -name '*.sql' -or -name '*.exs' -or -name '*.txt' -or -name '*.sh' -or -name '*.md' \) -delete
find . -type f \( -name '1.py' \) -delete
cd ..
