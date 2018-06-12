import numpy as np
import sys

#if __name__=="__main__":
    
print (sys.argv[1])    
    #for line in open("newtopic"):
f1 = open ( sys.argv[1] , 'r')

lA = [[(num.replace("\n","")) for num in line.split(' ')] for line in f1 ]




f2 = open ( sys.argv[2] , 'r')

lB = [[(num.replace("\n","")) for num in line.split('\t')] for line in f2 ]


l2=[]
iii=0
for i in range(len(lA)):
    #print(lA[i] )
    #print(lB[i][0])
    col=[]
    col.append((float(lB[i][0])))
    col.append(str(lA[i][0]))
    l2.append(col)
   
    #iii+=1
   
    
l2.sort(key=lambda l2:l2[0])




##l2.sort(key=lambda l2:l2[0])
##print (l2)

f1 = open ( 'newtopic.sort' , 'w')


f3 = open ( sys.argv[3] , 'r')
lC = [(line.replace("\n",""))  for line in f3 ]
#print (lC)
for linha in l2:
    if (sys.argv[4] == "1" and not str(linha[1]) in lC):
        #print (linha)
        f1.write(str(linha[1]).zfill(5) + " " + str(linha[0]) +"\n")
    if (sys.argv[4] == "0"):
    
        f1.write(str(linha[1]).zfill(5) + " " + str(linha[0]) +"\n")
        #print ("errrooooooooooooooooO")
    #for linha in lC:
        ##print (str(linha[0]) +" " +  str(element[1]))
        #if(linha[0] == str(element[1])):
            #print (element)


    
    

#f1.close()

#x=np.loadtxt("newtopic")
#y=x[np.lexsort((x[:, 1], ))]
#print (y)



#str=np.array_str(y)
#print (str)
#np.savetxt('test.out', y, delimiter=' ', fmt="%03d %10.5f") 