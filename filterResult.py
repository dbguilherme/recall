import sys

f1 = open ( sys.argv[1] , 'r')
f2 = open ( "result" , 'w')


t=float(sys.argv[2])

for i in f1:
    if(float(i.split(" ")[1])>=t):
        f2.write(i.split(" ")[0] +"\n")
        print(float(i.split(" ")[1]), "  ", t)
        
f2.close()
