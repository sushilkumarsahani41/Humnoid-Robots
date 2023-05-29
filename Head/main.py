import cv2 as cv

cap = cv.VideoCapture(1)

tracker = cv.legacy.TrackerMOSSE_create()
success, img = cap.read()
bbox = cv.selectROI("Tracking",img,False)
tracker.init(img,bbox)

def drawBox():
    pass

while True:

    timer = cv.getTickCount()
    success, img = cap.read()
    success, img = tracker.update(img)
    if success:
        drawBox()
    else:
        cv.putText(img,"Lost",(75,100),cv.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2) 
    fps = cv.getTickFrequency()/(cv.getTickCount() - timer)
    cv.putText(img,str(int(fps)),(75,50),cv.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2)
    cv.imshow('Tracking', img)

    if cv.waitKey(1) & 0xFF == ord('q'):
        break