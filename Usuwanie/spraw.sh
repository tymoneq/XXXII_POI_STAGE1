g++ -std=c++17 -o a.exe -g usu.cpp
g++ spraw.cpp -o spraw.exe
for((i=0 ; i<5;i++))
do
echo $i
    time ./a.exe < usu$i.in > wynik.txt
    ./spraw.exe < usu$i.out > res.txt

    
done
