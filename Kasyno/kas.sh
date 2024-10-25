g++ -O3 -static -o kas kas.cpp -std=c++20

for((i=1 ; i<=1000 ; i++))

do
    echo $i
    echo  $i > ziarno
    
    ./kas < ziarno



done
