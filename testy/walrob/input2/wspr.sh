g++ -std=c++17 wal.cpp -o wzor.e


for((i=1 ; i<=1000;i++))
do

    ./wzor.e < test$i.in > wzor.out

    if diff -b test$i.out wzor.out > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi
    
done
