#
# simple example of union-find
#

def make_set(n):
  arr = list(xrange(0,n))
  return arr

def union(arr, i, j):
  arr[j] = i

def find(arr, i):
  if arr[i] != i:
    # path compression
    arr[i] = find(arr, arr[i])
  return arr[i]

def number_of_connected(n, edges):
  arr = make_set(n)
  for x,y in edges:
    union(arr, x, y)
  ret = set()
  for i in arr:
    ret.add(find(arr, i))
  return len(ret)

input = [[0, 1], [1, 2], [3, 4]]
#input = [[0, 1], [1, 2], [2, 3], [3, 4]]
num = number_of_connected(5, input)

print "num: %d" % num
