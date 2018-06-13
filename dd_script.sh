
sample_input=$1

#./indexer /home/guilherme/Downloads/tar-toolkit-core-copy/logistic/svm.fil 201.db 69 256000

 while IFS='' read -r line || [[ -n $line ]]; do
 #echo $line
    
    add=`echo $line | cut -d' ' -f2 | ../kissdb/indexer ../kissdb/201.db 69 25000`
    #echo $add
    
    dd if=svm.fil ibs=1 skip=$add count=241957 status=none | grep "^legal" | cut -d$'\n' -f1 
 
 
 done < $sample_input