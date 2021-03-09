find . -name "*.txt" -exec bash -c 'mv "$1" "${1%.txt}".ascii' - {} \;

