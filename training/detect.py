import tensorflow as tf
import os
import pathlib
import numpy as np



def load_model(path_to_frozen_graph):
    model = tf.saved_model.load(path_to_frozen_graph)
    model = model.signatures['serving_default']
    return model


def main():
    path_to_frozen_graph = "./trained-inference-graphs/output_inference_graph_v1.pb/saved_model"
    #path_to_labels = 'training/annotations/label_map.pbtxt'
    model = load_model(path_to_frozen_graph)
    print(model.inputs)
if __name__ == "__main__":
    main()
