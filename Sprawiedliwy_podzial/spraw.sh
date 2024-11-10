g++ -O3 -static -std=c++20 spr.cpp -o wzor.e
g++ -O3 -static -std=c++20 gen.cpp -o gen.e
g++ -O3 -static -std=c++20 checker.cpp -o checker.e

for((i=1 ; i>0 ; i++))

do
    # echo $i
    echo $i > ziarno

    ./gen.e < ziarno > test.in
    ./wzor.e < test.in > wzor.out
    ./checker.e < wzor.out > ans.txt


    if diff -b ans.txt a.txt > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi

done
