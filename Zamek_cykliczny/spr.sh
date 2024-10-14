g++ -std=c++17 zam.cpp -o wzor.e
g++ gen.cpp -o g.e
g++ -std=c++17 zamek_brut.cpp -o brut.e

for((i=1 ; i>0;i++))
do
echo $i > ziarno
    ./g.e < ziarno > test.in
    ./wzor.e < test.in > wzor.out
    ./brut.e < test.in > brut.out
    
    if diff -b brut.out wzor.out > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi
    
done
