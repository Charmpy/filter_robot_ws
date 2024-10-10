# filter_robot_ws
From robot scripts rtk


Код для распбери - закинуть всю папку на малинку, перейти в папку и в папке filter_robot_ws:

```
colcon build
source /opt/ros/humble/setup.bash ## Писать при каждом включении терминала!
source install/setup.bash   ### Это тоже !
ros2 run v4l2_camera v4l2_camera_node
```
В результате будет болшая ошибка (Но если код не прекращается, то всё окей):

```
[INFO] [1728317615.330054920] [v4l2_camera]: Driver: bm2835 mmal
[INFO] [1728317615.330706052] [v4l2_camera]: Version: 331683
[INFO] [1728317615.330824345] [v4l2_camera]: Device: mmal service 16.1
[INFO] [1728317615.330889010] [v4l2_camera]: Location: platform:bcm2835-v4l2-0
[INFO] [1728317615.330991415] [v4l2_camera]: Capabilities:
[INFO] [1728317615.331052081] [v4l2_camera]:   Read/write: YES
[INFO] [1728317615.331106783] [v4l2_camera]:   Streaming: YES
[INFO] [1728317615.331200169] [v4l2_camera]: Current pixel format: JPEG @ 1024x768
[INFO] [1728317615.333251804] [v4l2_camera]: Available pixel formats: 
[INFO] [1728317615.333376375] [v4l2_camera]:   YU12 - Planar YUV 4:2:0
[INFO] [1728317615.333431207] [v4l2_camera]:   YUYV - YUYV 4:2:2
[INFO] [1728317615.333477928] [v4l2_camera]:   RGB3 - 24-bit RGB 8-8-8
[INFO] [1728317615.333525409] [v4l2_camera]:   JPEG - JFIF JPEG
[INFO] [1728317615.333570426] [v4l2_camera]:   H264 - H.264
[INFO] [1728317615.333614055] [v4l2_camera]:   MJPG - Motion-JPEG
[INFO] [1728317615.333658516] [v4l2_camera]:   YVYU - YVYU 4:2:2
[INFO] [1728317615.333703256] [v4l2_camera]:   VYUY - VYUY 4:2:2
[INFO] [1728317615.333746551] [v4l2_camera]:   UYVY - UYVY 4:2:2
[INFO] [1728317615.333789643] [v4l2_camera]:   NV12 - Y/CbCr 4:2:0
[INFO] [1728317615.333834401] [v4l2_camera]:   BGR3 - 24-bit BGR 8-8-8
[INFO] [1728317615.333879122] [v4l2_camera]:   YV12 - Planar YVU 4:2:0
[INFO] [1728317615.333922010] [v4l2_camera]:   NV21 - Y/CrCb 4:2:0
[INFO] [1728317615.333965861] [v4l2_camera]:   RX24 - 32-bit XBGR 8-8-8-8
[INFO] [1728317615.334018137] [v4l2_camera]: Available controls: 
[INFO] [1728317615.334098006] [v4l2_camera]:   Brightness (1) = 50
[INFO] [1728317615.334168689] [v4l2_camera]:   Contrast (1) = 0
[INFO] [1728317615.334234651] [v4l2_camera]:   Saturation (1) = 0
[INFO] [1728317615.334297779] [v4l2_camera]:   Red Balance (1) = 1000
[INFO] [1728317615.334359388] [v4l2_camera]:   Blue Balance (1) = 1000
[INFO] [1728317615.334421553] [v4l2_camera]:   Horizontal Flip (2) = 0
[INFO] [1728317615.334481052] [v4l2_camera]:   Vertical Flip (2) = 0
[INFO] [1728317615.334541143] [v4l2_camera]:   Power Line Frequency (3) = 1
[INFO] [1728317615.334600179] [v4l2_camera]:   Sharpness (1) = 0
[INFO] [1728317615.334659529] [v4l2_camera]:   Color Effects (3) = 0
[INFO] [1728317615.334720453] [v4l2_camera]:   Rotate (1) = 0
[INFO] [1728317615.334782119] [v4l2_camera]:   Color Effects, CbCr (1) = 32896
[ERROR] [1728317615.334857617] [v4l2_camera]: Failed getting value for control 10027009: Permission denied (13); returning 0!
[INFO] [1728317615.334916930] [v4l2_camera]:   Codec Controls (6) = 0
[INFO] [1728317615.335032909] [v4l2_camera]:   Video Bitrate Mode (3) = 0
[INFO] [1728317615.335099851] [v4l2_camera]:   Video Bitrate (1) = 10000000
[INFO] [1728317615.335161813] [v4l2_camera]:   Repeat Sequence Header (2) = 0
[ERROR] [1728317615.335224274] [v4l2_camera]: Failed getting value for control 10029541: Permission denied (13); returning 0!
[INFO] [1728317615.335273736] [v4l2_camera]:   Force Key Frame (4) = 0
[INFO] [1728317615.335333438] [v4l2_camera]:   H264 Minimum QP Value (1) = 0
[INFO] [1728317615.335390437] [v4l2_camera]:   H264 Maximum QP Value (1) = 0
[INFO] [1728317615.335450528] [v4l2_camera]:   H264 I-Frame Period (1) = 60
[INFO] [1728317615.335509304] [v4l2_camera]:   H264 Level (3) = 11
[INFO] [1728317615.335574006] [v4l2_camera]:   H264 Profile (3) = 4
[ERROR] [1728317615.335640616] [v4l2_camera]: Failed getting value for control 10092545: Permission denied (13); returning 0!
[INFO] [1728317615.335697115] [v4l2_camera]:   Camera Controls (6) = 0
[INFO] [1728317615.335765835] [v4l2_camera]:   Auto Exposure (3) = 0
[INFO] [1728317615.335834056] [v4l2_camera]:   Exposure Time, Absolute (1) = 1000
[INFO] [1728317615.335905276] [v4l2_camera]:   Exposure, Dynamic Framerate (2) = 0
[INFO] [1728317615.335972330] [v4l2_camera]:   Auto Exposure, Bias (9) = 12
[INFO] [1728317615.336038606] [v4l2_camera]:   White Balance, Auto & Preset (3) = 1
[INFO] [1728317615.336103142] [v4l2_camera]:   Image Stabilization (2) = 0
[INFO] [1728317615.336356450] [v4l2_camera]:   ISO Sensitivity (9) = 0
[INFO] [1728317615.336506817] [v4l2_camera]:   ISO Sensitivity, Auto (3) = 1
[INFO] [1728317615.336606703] [v4l2_camera]:   Exposure, Metering Mode (3) = 0
[INFO] [1728317615.336738237] [v4l2_camera]:   Scene Mode (3) = 0
[ERROR] [1728317615.336836272] [v4l2_camera]: Failed getting value for control 10289153: Permission denied (13); returning 0!
[INFO] [1728317615.336904511] [v4l2_camera]:   JPEG Compression Controls (6) = 0
[INFO] [1728317615.336974805] [v4l2_camera]:   Compression Quality (1) = 30
[WARN] [1728317615.340704881] [v4l2_camera]: Control type not currently supported: 6, for control: Codec Controls
[WARN] [1728317615.341214738] [v4l2_camera]: Control type not currently supported: 4, for control: Force Key Frame
[WARN] [1728317615.341718856] [v4l2_camera]: Control type not currently supported: 6, for control: Camera Controls
[WARN] [1728317615.342052644] [v4l2_camera]: Control type not currently supported: 9, for control: Auto Exposure, Bias
[WARN] [1728317615.342328470] [v4l2_camera]: Control type not currently supported: 9, for control: ISO Sensitivity
[WARN] [1728317615.342700332] [v4l2_camera]: Control type not currently supported: 6, for control: JPEG Compression Controls
[INFO] [1728317615.342970306] [v4l2_camera]: Requesting format: 1024x768 YUYV
[INFO] [1728317615.348842273] [v4l2_camera]: Success
[INFO] [1728317615.349115470] [v4l2_camera]: Requesting format: 640x480 YUYV
[INFO] [1728317615.349656698] [v4l2_camera]: Success
[INFO] [1728317615.353939926] [v4l2_camera]: Starting camera
[WARN] [1728317616.031391424] [v4l2_camera]: Image encoding not the same as requested output, performing possibly slow conversion: yuv422_yuy2 => rgb8
[INFO] [1728317616.068216129] [v4l2_camera]: using default calibration URL
[INFO] [1728317616.068437106] [v4l2_camera]: camera calibration URL: file:///home/pi/.ros/camera_info/mmal_service_16.1.yaml
[ERROR] [1728317616.068761431] [camera_calibration_parsers]: Unable to open camera calibration file [/home/pi/.ros/camera_info/mmal_service_16.1.yaml]
[WARN] [1728317616.068879373] [v4l2_camera]: Camera calibration file /home/pi/.ros/camera_info/mmal_service_16.1.yaml not found
```
Теперь в новом терминале, но тоже на Распберри (Пакет нужно будет скачать image-transport-plugins):

```
colcon build
source /opt/ros/humble/setup.bash ## Писать при каждом включении терминала!
source install/setup.bash   ### Это тоже !
ros2 run image_transport republish raw in:=/image_raw  compressed out:=/image_compressed

```

2 желтые строчки и если код не завершается, то всё окей