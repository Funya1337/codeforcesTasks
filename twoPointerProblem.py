arr = [1, 3, 2, 5, 1, 1, 2, 3]

arr.sort(reverse = True)

s = 1

def twoPointerProblem(arr, s):
  n = 0
  m = 0
  checker = False

  while n != len(arr) - 1 and m != len(arr) - 1:
    m += 1
    if sum(arr[n:m]) > s:
      n += 1
      m = n
    elif sum(arr[n:m]) == s:
      checker = True
      print(arr[n:m])
      break
    elif m == len(arr) - 1:
      n += 1
      m = n
  return checker

print(twoPointerProblem(arr, s))
