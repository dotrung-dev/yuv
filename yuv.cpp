//Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace nullifies the use of cv::function();
using namespace std;
using namespace cv;
class YUVRGBConvert {
public:
		YUVRGBConvert(const char *image, int height, int width): _image((const char *) image), _height(height), _width(width)
		{
			yuv = Mat(_height*3/2,_width, CV_8UC1);
			_mat_display = Mat(_height, _width, CV_8UC3);
			ReadImage();
			Convert();
		}
		void Display ()
		{
			imshow("Image YUV show", _mat_display);
			// Wait for a keystroke.
			waitKey(0);
			// Destroys all the windows created
			destroyAllWindows();
		}

private:
		void ReadImage ()
		{
			FILE *file = fopen(_image, "r");
			fread(yuv.data, sizeof(char), _size_image, file);
			fclose(file);
		}
		void Convert ()
		{
			cvtColor(yuv, _mat_display,  cv::COLOR_YUV2RGBA_YV12);
		}
		int _height;
		int _width;
		const char *_image;
		Mat _mat_display;
		Mat yuv;
		int _size_image = _height*_width*3/2;
};
int main () {
	YUVRGBConvert("tulips_yuv422_inter_planar_qcif.yuv",144,176).Display();
}
