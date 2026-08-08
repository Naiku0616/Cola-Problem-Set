a=int(input())
b=list(map(int,input().split()))
print(f"{1 if max(b)==min(b) else 2} {max(b)-min(b)}")
