g++ -O3 -static zam.cpp -std=c++20 -o wzor.e

for((i=0 ; i<100001;i++))
do
echo $i > ziarno
    ./wzor.e < test$i.in > wzor.out

    
    if diff -b test$i.out wzor.out > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi
    
done
