# O3X100
Contains a simple C++ program which uses the ifm3d library to capture and output a point cloud as text data, as well as its CMake build script and a sample point cloud showing my hand in front of a wall.

## Building the capture program
Build steps for the ifm3d library adapted from https://github.com/lovepark/ifm3d specifically for the O3X100 camera.

### Dependencies

### Git
`sudo apt-get install git`

#### OpenCV
The only dependency which needs to be built from source.  
Follow the instructions here to install (the optional parts are not required for the capture program to build): https://docs.opencv.org/trunk/d7/d9f/tutorial_linux_install.html

#### Others 
`sudo apt-get install libboost-all-dev libgtest-dev libgoogle-glog-dev libxmlrpc-dev cmake libpcl-dev binutils dpkg`

### Build ifm3d
Once all the dependencies are installed, the ifm3d library must be built.  
  
Clone the git repository of ifm3d:  
`git clone https://github.com/lovepark/ifm3d.git`  
  
Run these commands:  
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr ..
make
make package
make repackage
sudo dpkg -i ifm3d*camera.deb
sudo dpkg -i ifm3d*framegrabber.deb
sudo dpkg -i ifm3d*image.deb
sudo dpkg -i ifm3d*tools.deb
```

### Build capture program using CMake
`cd` into `O3X100/` (this directory - where the O3X100.cpp source code resides).  
  
Run these commands:
```
mkdir build
cd build
cmake ..
make
```
  
The code should compile successfully, and a new executable `O3X100` is created in the `build/` directory.

## Running the capture program
Before running the executable, make sure the camera is connected to the camera and is powered on. Also make sure that camera communication is possible using `ping`, for example:  
`ping 192.168.0.69`  
  
The default IP address for the camera is `192.168.0.69`, but you can manually change that using the Vision Assistant program (Windows only) downloaded from here (select E3D300 ifmVisionAssistant): https://www.ifm.com/ifmus/web/dualis-download.htm  
  
If the IP address has been changed, export the new IP address to the `IFM3D_IP` environment variable like so:  
`export IFM3D_IP=192.168.1.50`  
  
Run the capture program by:  
`./O3X100`  
  
The program prints the point cloud data to `stdout`, which means the output can be redirected into a text file like so:  
`./O3X100 > cloud.txt`  
  
The text file can then be imported into MATLAB and plotted like so:
```
cloud = importdata("cloud.txt");
pcshow(cloud(:,1:3), cloud(:,4));
```
  
Using the sample cloud data of my hand, it looks something like this:  
![](https://github.com/YiweiHan/Thesis/raw/master/O3X100/hand_cloud.png)
