from skimage.io import imread
from skimage.transform import resize
from matplotlib import pyplot as plt
import matplotlib.cm as cm

egImg = "horse0.png"
img = imread(egImg, as_gray = True)
plt.imshow(img, cmap = cm.gray)
plt.show()


import numpy as np
check = np.zeros((9, 9))
check[::2, 1::2] = 1
check[1::2, ::2] = 1
import matplotlib.pyplot as plt
plt.imshow(check, cmap='gray', interpolation='nearest') 
plt.show()
