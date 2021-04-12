import cv2
import tensorflow as tf
import numpy as np

def high_pass(fshift,freq):
    cy,cx = fshift.shape[0]/2,fshift.shape[1]/2
    h = np.arange(fshift.shape[0]).reshape((-1,1))-cy
    w = np.arange(fshift.shape[1]).reshape((1,-1))-cx
    freq = freq **2
    fshift = np.where(h**2+w**2 >=freq,fshift,0)
    return fshift

def low_pass(fshift,freq):
    cy,cx = fshift.shape[0]/2,fshift.shape[1]/2
    h = np.arange(fshift.shape[0]).reshape((-1,1))-cy
    w = np.arange(fshift.shape[1]).reshape((1,-1))-cx
    freq = freq **2
    fshift = np.where(h**2+w**2 <=freq,fshift,0)
    return fshift

def pre_high_pass(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    f = np.fft.fft2(gray)
    fshift = np.fft.fftshift(f)
    high_pass_f = high_pass(fshift.copy(),10)
    ifft_f = np.fft.ifft2(np.fft.fftshift(high_pass_f))
    img = np.abs(ifft_f).astype(np.uint8)
    img = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
    return img

def pre_low_pass(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    f = np.fft.fft2(gray)
    fshift = np.fft.fftshift(f)
    high_pass_f = low_pass(fshift.copy(),40)
    ifft_f = np.fft.ifft2(np.fft.fftshift(high_pass_f))
    img = np.abs(ifft_f).astype(np.uint8)
    img = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
    return img

def gray_scale(frame):
    img = cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
    img = tf.image.rgb_to_grayscale(img)
    img = tf.image.grayscale_to_rgb(img).numpy()
    img = cv2.cvtColor(img,cv2.COLOR_RGB2BGR)
    return img
def sharp_unsharp_masking(original,k,sigma):
    blur_image = cv2.GaussianBlur(original,(0,0),sigma).astype(np.int)
    original= original.astype(np.int)
    sharpen_image = original+k*(original-blur_image)
    x = sharpen_image.ravel()
    x[x<0]=0
    x[x>255]=255
    return sharpen_image.astype(np.uint8)
def hsv_more_colorful(frame):
    img = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    s = (img[:,:,1].astype(np.uint8)*2.0)
    s[s>255]=255
    img[:,:,1]=s
    img = cv2.cvtColor(img,cv2.COLOR_HSV2BGR)
    return img
def negative_film(frame):
    img = 255 - frame
    return img
if __name__ == '__main__':    
    cap=cv2.VideoCapture('testvideo.mp4')
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter('output.mp4',fourcc, 30.0, (1920,1080))
    while cap.isOpened():
        ret , frame = cap.read()
        if ret == True:
            shp= sharp_unsharp_masking(frame,3,5)
            cv2.putText(shp,"sharp unsharp masking",(10,40),cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,0),2,cv2.LINE_AA)
            hsv = hsv_more_colorful(frame)
            cv2.putText(hsv,"more colorful",(10,40),cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,0),2,cv2.LINE_AA)
            neg = negative_film(frame)
            cv2.putText(neg,"negative film",(10,40),cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,0),2,cv2.LINE_AA)
            hgh = pre_high_pass(frame)
            cv2.putText(hgh,"high pass",(10,40),cv2.FONT_HERSHEY_SIMPLEX,1,(255,255,255),2,cv2.LINE_AA)
            low = pre_low_pass(frame)
            cv2.putText(low,"low pass",(10,40),cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,0),2,cv2.LINE_AA)
            gry = gray_scale(frame)
            cv2.putText(gry,"gray scale",(10,40),cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,0),2,cv2.LINE_AA)
            video_row_1 = cv2.hconcat([shp,hsv,neg])
            video_row_2 = cv2.hconcat([hgh,low,gry])
            video = cv2.vconcat([video_row_1,video_row_2])
            video = cv2.resize(video,(1920,1080))
            out.write(video)            
        else:
            break
    cap.release()
    out.release()
    cv2.destroyAllWindows()
    
# the result video https://youtu.be/QXfZeh-ip4c