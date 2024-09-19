#include <opencv2/opencv.hpp>
#include <iostream>

void showImage(const cv::Mat& img, const std::string& title) {
    cv::imshow(title, img);
    cv::waitKey(0);
}

int main() {
    std::string filepath = "path/to/image.jpg";
    cv::Mat image = cv::imread(filepath);

    if (image.empty()) {
        std::cerr << "Error loading image!" << std::endl;
        return -1;
    }

    cv::Mat grayImage = applyGrayscale(image);
    showImage(grayImage, "Grayscale Image");

    cv::Mat blurredImage = applyBlur(image);
    showImage(blurredImage, "Blurred Image");

    cv::Mat sharpenedImage = applySharpen(image);
    showImage(sharpenedImage, "Sharpened Image");

    cv::Mat resizedImage = resizeImage(image, cv::Size(200, 200));
    showImage(resizedImage, "Resized Image");

    saveImage(resizedImage, "path/to/save/image.jpg");

    return 0;
}
