from skimage.segmentation import slic
from skimage.util import img_as_float
from skimage import io as skimageIO
from segraph import create_graph
import numpy as np

from skimage.io import imsave
from skimage import color
from matplotlib import pyplot as plt
def show_img(img):
	print 'hola';
	width = 10.0
	height = img.shape[0]*width/img.shape[1]
	f = plt.figure(figsize=(width, height))
	plt.imshow(img)
	plt.show()


#image = img_as_float(skimageIO.imread("flowers.png"))
image= skimageIO.imread("horse.png", as_gray = False)
#show_img(image)

segments = slic(image,compactness=30, n_segments=500, sigma=1.0)
label_rgb = color.label2rgb(segments, image, kind='avg')
show_img(label_rgb)
print ( np.matrix(segments))

imsave("segments.ppm", segments)
np.savetxt('segments.out',segments, fmt='%.0f')
#file = open('segments.out','w')
#file.write(segments)
#file.close()

# Create graph of superpixels 

segments2 = np.array([
	   [ 0.,  0.,  0.,  1.,  1., 2., 2.],
       [ 0.,  0.,  0.,  1.,  1., 2., 2.],
       [ 0.,  0.,  0.,  1.,  1., 2., 2.],
       [ 3.,  3.,  3.,  4.,  4., 5., 5.],
       [ 3.,  3.,  3.,  4.,  4., 5., 5.]])


segments3 = np.array([
	   [ 0.,  1.,  2.,  3.,  4., 5., 6.],
       [ 7.,  8.,  9.,  10.,  11., 12., 13.],
       [ 14.,  15.,  16.,  17.,  18., 19., 20.],
       [ 21.,  22.,  23.,  24.,  25., 26., 27.],
       [ 28.,  29.,  30.,  31.,  32., 33., 34.]])


vertices = np.unique(segments2)
num_vertices = len(vertices)
mapping = dict(zip(vertices, np.arange(num_vertices)))
mapped_grid = np.array([mapping[x] for x in segments2.flat]).reshape(segments2.shape)
print mapped_grid
l2r = np.c_[mapped_grid[:, :-1].ravel(), mapped_grid[:, 1:].ravel()]
t2b = np.c_[mapped_grid[:-1, :].ravel(), mapped_grid[1:, :].ravel()]

print len(l2r)
print len(t2b)
edges = np.vstack([l2r, t2b])
#print edges
print len(edges)

edges = edges[edges[:, 0] != edges[:, 1], :]
print edges
print len(edges)


vertices, edges = create_graph(segments2)
np.savetxt('vertices.out',vertices, fmt='%.0f')
np.savetxt('edges.out',edges, fmt='%.0f')

# Compute centers:
gridx, gridy = np.mgrid[:segments.shape[0], :segments.shape[1]]
centers = dict()
for v in vertices:
    centers[v] = [gridy[segments == v].mean(), gridx[segments == v].mean()]

