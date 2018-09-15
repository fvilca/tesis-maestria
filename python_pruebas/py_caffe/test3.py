import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
import caffe
caffe.set_device(0)
caffe.set_mode_gpu()

net = caffe.Net(
	'/home/fil/caffe/models/bvlc_reference_caffenet/deploy.prototxt', 
	'/home/fil/caffe/models/bvlc_reference_caffenet/bvlc_reference_caffenet.caffemodel',
	caffe.TEST)

print '************'

transformer = caffe.io.Transformer(
	{ 'data': net.blobs['data'].data.shape	}
)
transformer.set_mean('data', np.load('/home/fil/caffe/python/caffe/imagenet/ilsvrc_2012_mean.npy').mean(1).mean(1))
transformer.set_transpose('data', (2,0,1))
transformer.set_channel_swap('data',(2,1,0))
transformer.set_raw_scale('data',255.0)


net.blobs['data'].reshape(1,3,227,227)

im = caffe.io.load_image('/home/fil/caffe/examples/images/cat.jpg')
net.blobs['data'].data[...] = transformer.preprocess('data',im)

#out = net.forward()
out = net.forward_all(data=np.asarray([transformer.preprocess('data', im)]))
print out['prob'].argmax()

labels = np.loadtxt("/home/fil/caffe/data/ilsvrc12/synset_words.txt", str, delimiter='\t')
top_k = net.blobs['prob'].data[0].flatten().argsort()[-1:-6:-1]

print labels[top_k]