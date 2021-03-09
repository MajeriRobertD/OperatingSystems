maxnr=0
for f in $*;
do
	noWords=`awk ' {i=0; noWords=0;
	while(i<FNR){
		noWords += NF;
		i++;
	}}
       	END {printf noWords;}' $f`
	if [ "$noWords" > "$maxnr" ]
	then
		maxnr=$noWords;
		fname=$f

	fi
done
echo "The file with max words is $fname with total of $maxnr words!";
