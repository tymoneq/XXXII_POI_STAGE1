g++ -std=c++17 usu.cpp -o w.e
g++ gen.cpp -o g.e
g++ -std=c++17 usuwanieBrut.cpp -o b.e
for((i=1 ; i>0;i++))
do
echo $i
echo $i > ziarno
    ./g.e < ziarno > test.in
    time ./w.e < test.in > w.out
    ./b.e < test.in > b.out
    ./spraw.exe < b.out >> res.txt
    
done
