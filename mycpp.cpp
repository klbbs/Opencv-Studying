#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat image = cv::imread("../test4.jpg");
    if (image.empty()) {
        std::cerr << "Error: Could not load image!" << std::endl;
        return -1;
    }

    // 将图像转为灰度
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // 应用二值化操作（可以调节阈值）
    cv::Mat binary;
    cv::threshold(gray, binary, 60, 255, cv::THRESH_BINARY_INV); // 检测黑色

    // 开运算去噪
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::morphologyEx(binary, binary, cv::MORPH_OPEN, kernel);

    // 检测轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 画出每个轮廓的边界框
    double area_threshold = 500; // 设定面积阈值
    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > area_threshold) {
            cv::Rect bounding_box = cv::boundingRect(contours[i]);
            cv::rectangle(image, bounding_box, cv::Scalar(0, 255, 0), 5); // 用绿色画矩形框
        }
    }

    // 显示结果图像
    cv::namedWindow("Detected Objects", cv::WINDOW_NORMAL);
    cv::resizeWindow("Detected Objects", 800, 600);
    cv::imshow("Detected Objects", image);
    cv::waitKey(0);

    return 0;
}
