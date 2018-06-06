from sys import argv

file_name= argv
file = open("/tmp/seed_selected_cover","r")
out = open("/tmp/selected_pad","w")

for i in file:
    print(str(int(i)).zfill(5))