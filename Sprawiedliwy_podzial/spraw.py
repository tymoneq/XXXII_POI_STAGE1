

with open('wzor.out', 'r') as file:
    wzor = file.readline()

t = 0 

with open('brut.out', 'r') as f:
    for line in f:
        if line == wzor:
              t = 1

if not t:
    print("WRONG!!!!!!")