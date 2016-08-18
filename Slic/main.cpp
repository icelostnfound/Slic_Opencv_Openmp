#include "slic.h"
#include <cstdlib>
#include <cstdio>
#include "opencv2/core/core.hpp"
#include "opencv2/core/internal.hpp"
#include <windows.h>
#include <omp.h>
using namespace std;

int main(int argc, char** argv)
{
	/*if (argc != 3) {
		printf("usage: test_slic <filename> <number of superpixels>\n");
		exit(-1);
	}*/
	DWORD dwLast;
	DWORD dwCurrent;

	int numSuperpixel = 200;
	cout << "numSuperpixel: ";
	cin >> numSuperpixel;
	cout << endl;

	dwLast = GetTickCount();

	cv::Mat img, result;
	std::string file_path = "F:\\project\\ankoninc\\anconic20160812\\SLIC\\Slic\\tanaiw.jpg";
	img = cv::imread(file_path);
	

	SLIC slic;
	slic.GenerateSuperpixels(img, numSuperpixel);
	if (img.channels() == 3) 
		result = slic.GetImgWithContours(cv::Scalar(0, 0, 255));
	else
		result = slic.GetImgWithContours(cv::Scalar(128));
	cv::imshow("megen", result);

	dwCurrent = GetTickCount();

	cout << "It took "<<(dwCurrent - dwLast)/1000 << " s!" << endl;
	cv::waitKey(0);
	cv::imwrite("result.jpg", result);
}
