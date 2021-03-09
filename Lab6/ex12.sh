for f in $1/**/*.txt; do
	cat *.txt| sort | uniq -c | grep -v -F '1 ' 
done
grep 'duplicated entry' *.txt


