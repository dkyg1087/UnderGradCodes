import cv2
import tensorflow as tf
cap=cv2.VideoCapture('testvideo.mp4')
fourcc = cv2.VideoWriter_fourcc(*'mp4v')
out = cv2.VideoWriter('output.mp4',fourcc, 30.0, (800,600))
while(cap.isOpened()):
    ret , frame = cap.read()
    gray = cv2.cvtColor(cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY),cv2.COLOR_GRAY2BGR)
    videoTest = cv2.hconcat([frame,gray])
    #tf.image.adjust_gamma(videoTest,0.2)
    videoTest = cv2.vconcat([videoTest,videoTest])
    videoTest = cv2.resize(videoTest,(800,600))
    out.write(videoTest)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
out.release()
cv2.destroyAllWindows()