import numpy as np
#a = np.zeros((2,5,5))
a = np.arange(50).reshape(2,5,5)

print a
print np.argmax(a)
#seg_map = result.argmax(axis=0)[0:5, 0:5]
b = a.argmax(axis=0)[0:5, 0:5]
print b