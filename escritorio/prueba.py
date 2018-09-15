import numpy as np
import scipy.io as sio
import os
import time
from PIL import Image as PILImage
import cv2
import argparse

#from config import *

def main():
    print "hola"
    spixel_fname = '3.pgm'
    spixel_values = cv2.imread(spixel_fname,cv2.IMREAD_UNCHANGED)
    #cv2.imshow('asa',spixel_values)
    #k = cv2.waitKey(0)
    #if k ==27:
        #cv2.destroyAllWindows()
    spixel_index = np.array(spixel_values).astype(np.float32)
    
     width, height, channels = im.shape
     # Pad as necessary
    pad_h = np.max([0, 513 - height])
    pad_w = np.max([0, 513 - width])
    spixel_index = np.lib.pad(spixel_index, ((0, pad_w), (0, pad_h)), 'constant', constant_values=100000)
    print spixel_index[0]
    #spixel_index = np.expand_dims(np.expand_dims(spixel_index, axis=0), axis = 0)


if __name__ == '__main__':
    main()
