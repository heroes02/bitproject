import rospy
import numpy as np
import cv2
import time
from py_test.msg import Num
from sensor_msgs.msg import CompressedImage, Image
from PySide2.QtCore import QThread, Signal, Slot
from PySide2.QtGui import QPixmap, QImage
from cv_bridge import CvBridge, CvBridgeError


class Worker(QThread):
    send_camera_view = Signal(object)
    def __init__(self, parent=None, tfnet=None):
        super(Worker, self).__init__()
        #self.main = parent
        self.tfnet = tfnet
        self.bridge = CvBridge()
        self.predic_flag = 0
        self.resize_width = 720
        self.resize_height = 480
        self.cappub = rospy.Publisher('chatter',Num,queue_size=20)

        rospy.Subscriber("/camera_topic", CompressedImage, self.callback)

    def __del__(self):
        print("=============================== End Camera Thread ==================================")


    def callback(self, data):
        try:

            self.cv_image = self.bridge.compressed_imgmsg_to_cv2(data)# encoding
#            self.results = self.tfnet.return_predict(self.cv_image)
#            self.cv_image = self.boxing(self.cv_image, self.results)
            self.cv_image = cv2.resize(self.cv_image, dsize=(self.resize_width, self.resize_height))
            self.stime = time.time()
            if(self.predic_flag == 0):
                self.results = self.tfnet.return_predict(self.cv_image)
                self.cv_image = self.boxing(self.cv_image, self.results)
                print('FPS {:.1f}'.format(1 / (time.time() - self.stime)))
                self.predic_flag = 0
            else:
                self.predic_flag += 1
            self.height, self.width, self.channel = self.cv_image.shape
            self.cv_image = cv2.cvtColor(self.cv_image, cv2.COLOR_BGR2RGB)

            self.bytesPerLine = 3 * self.width
            self.qt_image = QImage(self.cv_image, self.width, self.height, self.bytesPerLine, QImage.Format_RGB888)
            self.pixmap = QPixmap.fromImage(self.qt_image)

            self.send_camera_view.emit(self.pixmap)
        except CvBridgeError as e:
            print(e)

    def boxing(self, original_img, predictions):
        self.newImage = np.copy(original_img)
        self.bound_cnt = 0
        self.bound_flag = 0

        for result in predictions:
            self.top_x = result['topleft']['x']
            self.top_y = result['topleft']['y']

            self.btm_x = result['bottomright']['x']
            self.btm_y = result['bottomright']['y']

            self.confidence = result['confidence']
            self.label = result['label'] + " " + str(round(self.confidence, 3))
            self.class_label = result['label']
            self.text = '{}: {:.0f}%'.format(self.class_label, self.confidence * 100)
            if self.class_label == 'bookshelf' and (self.btm_y-self.top_y)*(self.btm_x-self.top_x)>=20000:
                self.bound_flag = True

            if self.class_label == 'bookshelf':
                self.newImage = cv2.rectangle(self.newImage, (self.top_x, self.top_y), (self.btm_x, self.btm_y), (255,0,0), 3)
            elif self.class_label == 'desktop':
                self.newImage = cv2.rectangle(self.newImage, (self.top_x, self.top_y), (self.btm_x, self.btm_y), (0,0,255), 3)
            else :
                self.newImage = cv2.rectangle(self.newImage, (self.top_x, self.top_y), (self.btm_x, self.btm_y), (255,255,255), 3)

            self.newImage = cv2.putText(self.newImage, self.label, (self.top_x, self.top_y-5), cv2.FONT_HERSHEY_COMPLEX_SMALL , 0.8, (0, 230, 0), 1, cv2.LINE_AA)

        if self.bound_flag:
            self.sendData = Num()  

            self.tlx = '{}'.format(self.top_x)
            self.tly = '{}'.format(self.top_y)
            self.brx = '{}'.format(self.btm_x)
            self.bry = '{}'.format(self.btm_y)

            self.sendData.tl_x = round(float(self.tlx)/self.resize_width,5)
            self.sendData.tl_y = round(float(self.tly)/self.resize_height,5)
            self.sendData.br_x = round(float(self.brx)/self.resize_width,5)
            self.sendData.br_y = round(float(self.bry)/self.resize_height,5)
            self.sendData.confidence = round(self.confidence.item(),5)


            self.cappub.publish(self.sendData)
            print("box_info_publishing~~!!")        


        return self.newImage
