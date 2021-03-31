import cv2
import tensorflow as tf

def grayScale(video):
    return cv2.cvtColor(cv2.cvtColor(video,cv2.COLOR_BGR2GRAY),cv2.COLOR_GRAY2BGR)

if __name__ == '__main__':
    cap=cv2.VideoCapture('testvideo.mp4')
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter('output.mp4',fourcc, 30.0, (1920,1080))
    while cap.isOpened():
        ret , video = cap.read()
        
        