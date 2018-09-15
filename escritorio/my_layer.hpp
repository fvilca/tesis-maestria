#ifndef MY_LAYER_HPP_
#define MY_LAYER_HPP_


#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

namespace caffe{

    template <typename DType>
    class myLayer: public Layer<Dtype> 
    {
    public:
        explicit myLayer(const LayerParameter& param): Layer<Dtype>(param){}
        virtual inline const char* type() const {return "My Layer"; }
        
        ~myLayer();

    };
}




#endif  // MY_LAYER_HPP_
