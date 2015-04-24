#include <iostream>

#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/core/core.hpp"
#include "lbp.hpp"
#include "histogram.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "USAGE: ./lbp_image [IMAGE]\n";
        return 1;
    }
    const string imagepath = argv[1];
    Mat src = imread(imagepath, CV_LOAD_IMAGE_GRAYSCALE);
    Mat lbp_img = lbp::OLBP(src);

    imshow("lbp", lbp_img);
    waitKey(0);
    /*
    Mat spatial_hist = lbp::uniformPatternSpatialHistogram(lbp_img, 256, 3, 3, 0);

    vector<int> feature_vector;
    for(int j = 0; j < spatial_hist.cols; ++j)
    {
        if(spatial_hist.at<int>(0, j) != -1)
            feature_vector.push_back(spatial_hist.at<int>(0, j));
    }

    for(int i = 0; i < feature_vector.size(); ++i)
    {
        if(i != (feature_vector.size() - 1))
            cout << feature_vector[i] << " ";
        else
            cout << feature_vector[i];
    }
    cout << "\n";
    */

    return 0;
}
