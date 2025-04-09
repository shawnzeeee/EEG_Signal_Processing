import onnx
from onnx_tf.backend import prepare

# Load your ONNX model
onnx_model = onnx.load("lstm_model.onnx")  # Replace with your model path
tf_rep = prepare(onnx_model)

# Export as a TensorFlow SavedModel
tf_rep.export_graph("TF folder")  # This will create a folder with TF model
