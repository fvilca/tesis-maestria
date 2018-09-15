
import numpy as np
import scipy.io as sio
import os
import time
from PIL import Image as PILImage
import cv2
import argparse


#from config import Config
import sys 
#CAFFE_ROOT = '/home/fil/Documentos/bilateralinceptions2/build/tmp_caffe_clone/src/CaffeUpstream/'
#sys.path.insert(0, CAFFE_ROOT + 'python')
import caffe
caffe.set_mode_gpu()





def do(prototxt, caffe_model):
	#f = file('simple.cfg')
	#cfg = Config(f)
	#print cfg.message
	#net = caffe.Net(modelo, pesos, caffe.TEST)
	net = caffe.Net(prototxt, caffe_model, caffe.TEST)
	print('Modelo cargado desde: ' + caffe_model)
	return

# ##################################
def main():
   	parser = argparse.ArgumentParser()
    
	parser.add_argument('--prototxt', type=str, required=True)
	parser.add_argument('--caffemodel', type=str, required=True)

	var_args = parser.parse_args()
	do(var_args.prototxt,var_args.caffemodel)


if __name__ == '__main__':
    main()
