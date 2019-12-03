for i in {1..100000}; do
    echo $i;
    for j in `seq 1 100`; do 
        echo $RANDOM $RANDOM;
    done > "tests/test$i.pts";
    time ./hull < "tests/test$i.pts" > "tests/time$i.txt";
done
