g++ -std=c++17 spr.cpp -o wzor.e
g++ gen.cpp -o gen.e
g++ -std=c++17 sprBrt.cpp -o brut.e


for((i=1 ; i>0 ; i++))

do
    echo $i
    echo $i > ziarno

    ./gen.e < ziarno > test.in
    time  ./wzor.e < test.in > wzor.out
    # ./brut.e < test.in > brut.out

    # python3 spraw.py

    # if diff -b wzor.out brut.out > /dev/null
    # then
    #     echo -ne "\e[1;32m$i\e[0m\r"
    # else
    #     echo -e "\e[1;31m$i\e[0m"
    #     break
    # fi



done
