how_many_tests=1
gap_between_tests=1000000
for i in `seq 1 $how_many_tests`; do
    echo $i;
    for j in `seq 1 $((i*gap_between_tests))`; do 
        echo $((-450 + RANDOM % 900)) $((-300 + RANDOM % 600));
    done > "tests/test$i.pts";
    ./hull < "tests/test$i.pts"; #>> "time.txt";
    sleep 0.01
done
