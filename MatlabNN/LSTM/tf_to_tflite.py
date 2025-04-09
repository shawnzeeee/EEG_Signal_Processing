import tensorflow as tf

converter = tf.lite.TFLiteConverter.from_saved_model("TF folder")

converter.target_spec.supported_ops = [
    tf.lite.OpsSet.TFLITE_BUILTINS,
    tf.lite.OpsSet.SELECT_TF_OPS
]
converter._experimental_lower_tensor_list_ops = False

tflite_model = converter.convert()

with open("lstm_model.tflite", "wb") as f:
    f.write(tflite_model)

print("TFLite model saved as 'model.tflite'")
