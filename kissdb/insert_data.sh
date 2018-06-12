
for z in xa* ; do
#         ../sof*/src/sof*ml --test_file $z --dimensionality 1100000 --model_in svm_model --results_file pout.$z
        echo $z
        ./indexer $z 201.db 69 256374        
        
done