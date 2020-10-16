import sys

def memo():
    return

n = int(input())
dp = [0 for _ in range(0,31)]
dp[0] = 0
dp[2] = 3
if n%2 == 1:
    print("0")
    exit()

for i in range(4,n+1):
    temp = 0
    for j in range(0,i):
        temp = temp+dp[j]
    dp[i] = dp[i-2]+3+2

print(dp[n])