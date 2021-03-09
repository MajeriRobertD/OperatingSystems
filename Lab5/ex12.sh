for f in $*; do
awk '{gsub(/word1/,"word2")}1' $f > temp.txt && mv temp.txt $f
done
