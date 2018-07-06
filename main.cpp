#include<iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
const int perBoardPixel = 114.5
;
const cv::Size boardSize(10,7);
const cv::Size resolution(1200,800);
int main()
{
	int basisHeight = (resolution.height - perBoardPixel*boardSize.height) / 2;
	int basisWidth = (resolution.width - perBoardPixel*boardSize.width) / 2;
	if( basisHeight < 0  ||  basisWidth < 0)
	{
		cout<<"Resolution doesn't match!"<<endl;
	}
	cv::Mat image(resolution,CV_8UC1,cv::Scalar::all(255));
	int flag = 0;
	for(int j = 0;j < boardSize.height;j++)
	{
		for(int i = 0;i < boardSize.width;i++)
		{
			flag = (i+j) % 2;
			if(flag == 0)
			{
				for(int n = j * perBoardPixel;n < (j+1) * perBoardPixel;n++)
					for(int m = i * perBoardPixel;m < (i+1) * perBoardPixel;m++)
						image.at<uchar>(n + basisHeight,m + basisWidth) = 0;
			}
		}
	}
	cv::imshow("haha",image);
	cv::imwrite("/home/lk/project/bd/haha.jpg",image);
	cv::waitKey(0);
	return 0;
}
