#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>
#include <ifm3d/camera.h>
#include <ifm3d/fg.h>
#include <ifm3d/image.h>

int main(int argc, const char **argv) {
    auto cam = ifm3d::Camera::MakeShared();
    auto fg = std::make_shared<ifm3d::FrameGrabber>(cam, ifm3d::IMG_CART);
    auto img = std::make_shared<ifm3d::ImageBuffer>();

    auto i = 0;
    // it might take the camera a few tries
    while (!fg->WaitForFrame(img.get(), 1000)) {
        if (i > 10) {
            std::cerr << "Timeout waiting for camera!" << std::endl;
            return -1;
        }
        ++i;
    }
    
    // print out the 3d co-ordinates
    for (const auto& p : *(img->Cloud())) {
        std::cout << p.data[0] << "," << p.data[1] << "," << p.data[2] << "," << p.intensity << std::endl;
    }

    return 0;
}
