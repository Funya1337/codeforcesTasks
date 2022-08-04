a1 = int(input())
n1 = list(map(int, input().split()))
a2 = int(input())
n2 = list(map(int, input().split()))
a3 = int(input())
n3 = list(map(int, input().split()))

res = n1 + n2 + n3
res.sort()
mid = len(res) // 2
print(res[mid - 1], res[mid + 1])
