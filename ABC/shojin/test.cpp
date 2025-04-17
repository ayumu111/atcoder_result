#include <opencv2/opencv.hpp>
#include <time.h>



#pragma CV_LIBRARY(core)
#pragma CV_LIBRARY(highgui)
#pragma CV_LIBRARY(imgcodecs)
#pragma CV_LIBRARY(videoio)

#pragma CV_LIBRARY(imgproc)
#pragma CV_LIBRARY(photo)

#pragma CV_LIBRARY(objdetect)
#pragma CV_LIBRARY(features2d)
#pragma CV_LIBRARY(calib3d)

#pragma CV_LIBRARY(superres)
#pragma CV_LIBRARY(videostab)

int bou();

Mat Right_to_Left(Mat src) {
	int center_width = src.cols /2;
	Mat dst = src.clone();

	//シンメトリー化(左部分を右に)
	for (int x = center_width; x < src.cols + 1; x++) {
		for (int y = 0; y < src.rows + 1; y++) {

			int idx = src.cols - x;
			dst.at<Vec3b>(y, x) = dst.at<Vec3b>(y, idx);

		}

	}

	return dst;
}

Mat Left_to_Right(Mat src) {
	int center_width = src.cols/2;
	Mat dst = src.clone();
	//シンメトリー化(右部分を左に)
	for (int x = center_width - 1; x >= 0; x--) { // cols - 1 ではなく center_width - 1

		for (int y = 0; y < src.rows; y++) {

			int idx = src.cols - 1 - x;
			dst.at<Vec3b>(y, x) = dst.at<Vec3b>(y, idx);
		}
	}
	return dst;
}

Mat Up_to_Down(Mat src) {
	int center_height = src.rows / 2;
	Mat dst = src.clone();
	for (int y = center_height; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			int idy = src.rows - y;
			dst.at<Vec3b>(y, x) = dst.at<Vec3b>(idy, x);
		}
	}
	return dst;

}

Mat Down_to_Up(Mat src) {
	int center_height = src.rows / 2;
	Mat dst = src.clone();
	for (int y = center_height; y > 0; y--) {
		for (int x = 0; x < src.cols; x++) {
			int idy = src.rows - y;
			dst.at<Vec3b>(y, x) = dst.at<Vec3b>(idy, x);
		}
	}
	return dst;

}

Mat Cluster_Con(Mat src ,const int cluster_count) {


	//画像の型変換
	Mat points;
	src.convertTo(points, CV_32FC3);
	points = points.reshape(3, src.rows * src.cols);

	Mat dst1 = src.clone();


	Mat clusters(points.size(), CV_8UC1);
    Mat centers;
	//クラスタリングを行う
	kmeans(points, cluster_count, clusters, TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 1.0),
		1, KMEANS_PP_CENTERS, centers);


	for (int y = 0; y < dst1.rows; y++)
	{
		for (int x = 0; x < dst1.cols; x++)
		{
			int idx = dst1.cols * y + x;

			//clustersの型はCV_32SC1だからintやで
			float tmpb = centers.at<float>(clusters.at<int>(idx, 0), 0);
			float tmpg = centers.at<float>(clusters.at<int>(idx, 0), 1);
			float tmpr = centers.at<float>(clusters.at<int>(idx, 0), 2);
			dst1.at<Vec3b>(y, x)[0] = saturate_cast<uchar>(tmpb);
			dst1.at<Vec3b>(y, x)[1] = saturate_cast<uchar>(tmpg);
			dst1.at<Vec3b>(y, x)[2] = saturate_cast<uchar>(tmpr);
		}
	}

	return dst1;
}



int Synmetry() {
	srand((unsigned int)time(NULL));
	//クラスタ数(少ないほど表現に使われる色が少ない)
	int n = rand() % 10;
	while (n <=1){
			n= rand() % 10;
	}

	const int cluster_count = n;
	//クラスタ数を出力
	cout << "今回のクラスタの数は" << cluster_count << "です。" << endl;

	//ソース画像を選択
    //Mat src = imread("sample/LINE.png");
	//Mat src = imread("lena.png");
	Mat src = imread("sample/panda.jpg");

	if (src.empty()) {
		cout << "画像の読み込みに失敗しました。" << endl;
		return 0;
	}
	
	
	
	Mat dst0 = Cluster_Con(src, cluster_count);
	Mat dst1 = Right_to_Left(dst0);
	Mat dst2 = Left_to_Right(dst0);
	Mat dst3 = Up_to_Down(dst1);

	
	//画像を出力
	imshow("src", src);
	imshow("Cluster_src", dst0);
	imshow("Right_to_Ledt_dst0", dst1);
	imshow("Left_to_Right_dst0", dst2);
	imshow("Up_to_Down_dst0", dst3);

	waitKey(0);


	return 0;
}

int main(int argc, const char** argv)
{
	
	Synmetry();
	
	return 0;
}