def max_sliding(lst, k):
  window = []
  ret = []
  # initial prep
  for i in xrange(min(k, len(lst))):
    while (len(window) > 0 and lst[window[-1]] < lst[i]):
      window.pop()
    window.append(i)
  ret.append(lst[window[0]])
  for i in xrange(k, len(lst)):
    if i-k == window[0]:
      window.pop(0)
    while (len(window) > 0 and lst[window[-1]] < lst[i]):
      window.pop()
    window.append(i)
    ret.append(lst[window[0]])
  return ret

input = [1,3,-1,-3,5,3,6,7]
answer = [3,3,5,5,6,7]
ret = max_sliding(input, 3)
print ret
print ret == answer
