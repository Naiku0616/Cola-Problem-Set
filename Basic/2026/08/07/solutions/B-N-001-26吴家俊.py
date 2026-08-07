n=input()
s=input()
while ("niu" in s) or ("mo" in s):
    s=s.replace("niu","")
    s=s.replace("mo","")
if s == "":
    print("Yes")
else:
    print("No")    
