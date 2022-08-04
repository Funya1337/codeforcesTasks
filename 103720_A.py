n = int(input())

if n % 3 == 0:
  x = n // 3
  print(4 * x * n)
else:
  x = n // 5
  print(12 * x * n)
