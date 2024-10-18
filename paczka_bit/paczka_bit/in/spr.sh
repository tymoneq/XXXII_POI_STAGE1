g++ -O3 -static -std=c++20 bitada.cpp -o wzor.e


for((i=1 ; i<=3333;i++))
do

    ./wzor.e < bit$i.in > wzor.out

    if diff -b bit$i.out wzor.out > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi
    
done
