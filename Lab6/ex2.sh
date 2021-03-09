mkdir Dictionary
for i in {a..z}
do
	awk -v letter=$i '{regex="^"letter".*";
       	for(j=1; j<=NF; j++) {
	       	if ($j ~ regex )
			{print $j } } }' $1 | sort -d >> Dictionary/$i.txt
done
