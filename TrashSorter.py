import cv2
import numpy as np
from tensorflow.keras.applications.vgg16 import preprocess_input
from PIL import Image
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing import image
import matplotlib.pyplot as plt
import serial
from serial import Serial
import time
import array as arr
#Used tutorial to train model --> https://github.com/supriya811106/Garbage-Classification-System
model = load_model("predictWaste12.h5")

output_class = ["battery", "biological", "brown-glass", "cardboard", "clothes", "green-glass", "metal", "paper", "plastic", "shoes", "trash", "white-glass"]

cap = cv2.VideoCapture(0)
recycle = ["shoes", "metal", "paper", "plastic", "cardboard","clothes"]
trash = ["battery", "biological", "trash"]
def waste_prediction(test_image):
   test_image = cv2.resize(test_image, (224, 224)) 
   test_image = image.img_to_array(test_image) / 255
   test_image = np.expand_dims(test_image, axis=0)
   predicted_array = model.predict(test_image)
   predicted_value = output_class[np.argmax(predicted_array)]
   predicted_accuracy = round(np.max(predicted_array) * 100, 2)
   if predicted_accuracy >= 80:
      return predicted_value
      
with serial.Serial('/dev/ttyACM0', 9600, timeout=10) as ser:
    while True:
        if ser.readline() == b'trash detected\r\n':
            ret, frame = cap.read()
            if ret == True:
                predicted = waste_prediction(frame)
            if predicted in recycle:
                print("recycle")
                ser.write(bytes('YES\n','utf-8'))
            elif predicted in trash:
                print("trash") 
                ser.write(bytes('NO\n','utf-8'))
            else:
                print("not cat" , predicted)
