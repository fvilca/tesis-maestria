from skimage import graph, data, io, segmentation, color
from matplotlib import pyplot as plt
from skimage.measure import regionprops
from skimage import draw
from skimage.io import imread
from skimage.io import imsave
import numpy as np
 
from skimage.future import graph
 
def display_edges(image, g, threshold):
    image = image.copy()
    for edge in g.edges_iter():
        n1, n2 = edge
 
        r1, c1 = map(int, rag.node[n1]['centroid'])
        r2, c2 = map(int, rag.node[n2]['centroid'])
 
        line  = draw.line(r1, c1, r2, c2)
        circle = draw.circle(r1,c1,1)
 
        if g[n1][n2]['weight'] < threshold :
            image[line] = 0,1,0
        image[circle] = 1,1,0
 
    return image

def show_img(img):
	print 'hola';
	width = 10.0
	height = img.shape[0]*width/img.shape[1]
	f = plt.figure(figsize=(width, height))
	plt.imshow(img)
	plt.show()

	
##
i = 'horse1.jpg'
img = imread(i, as_gray = False)

show_img(img)

#
labels = segmentation.slic(img, compactness=60, n_segments=4000) #400
labels = labels + 1  # So that no labelled region is 0 and ignored by regionprops
regions = regionprops(labels)

label_rgb = color.label2rgb(labels, img, kind='avg')
show_img(label_rgb)
imsave ("horse3.jpg", label_rgb)

label_rgb = segmentation.mark_boundaries(label_rgb, labels, (0, 0, 0))
show_img(label_rgb)
imsave ("horse4.jpg", label_rgb)


####################################

rag = graph.rag_mean_color(img,labels)
for region in regions:
    rag.node[region['label']]['centroid'] = region['centroid']

edges_drawn_all = display_edges(label_rgb, rag, np.inf)
show_img(edges_drawn_all)
imsave ("horse_graph.jpg", edges_drawn_all)
