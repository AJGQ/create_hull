how_many_tests=100
gap_between_tests=10000
for i in `seq 1 $how_many_tests`; do
    echo $i;
    for j in `seq 1 $((i*gap_between_tests))`; do 
        echo $RANDOM $RANDOM;
    done > "tests/test$i.pts";
    ./hull < "tests/test$i.pts" >> "time.txt";
    sleep 0.01
done
