#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/ml/ml.hpp"

using namespace std;
using namespace cv;

const int NUM_TRAINING_EXAMPLES = 80;
const int NUM_VALIDATION_EXAMPLES =  20;
const int NUM_FEATURES =  531;

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        cout << "USAGE: ./svm [TRAINING] [VALIDATION]\n";
        return 1;
    }
    const char* training_file = argv[1];
    const char* validation_file = argv[2];

    ifstream fin_t, fin_v;
    fin_t.open(training_file);
    fin_v.open(validation_file);

    Mat training_data(NUM_TRAINING_EXAMPLES, NUM_FEATURES, CV_32FC1);
    Mat class_labels(NUM_TRAINING_EXAMPLES, 1, CV_32FC1);
    Mat validation_data(NUM_VALIDATION_EXAMPLES, NUM_FEATURES, CV_32FC1);
    Mat prediction_results(NUM_VALIDATION_EXAMPLES, 1, CV_32FC1);

    for(int i = 0; i < NUM_TRAINING_EXAMPLES; ++i)
    {
        for(int j = 0; j < (NUM_FEATURES+1); ++j)
        {
            vector<float> example((NUM_FEATURES+1), 0.0f);
            fin_t >> example[j];

            if(j < NUM_FEATURES)
                training_data.at<float>(i, j) = example[j];
            else
                class_labels.at<float>(i, 0) = example[j];
        }
    }

    vector<float> correct_results(NUM_VALIDATION_EXAMPLES, 0.0f);
    for(int i = 0; i < NUM_VALIDATION_EXAMPLES; ++i)
    {
        for(int j = 0; j < (NUM_FEATURES+1); ++j)
        {
            if(j < NUM_FEATURES)
                fin_v >> validation_data.at<float>(i, j);
            else
                fin_v >> correct_results[i];
        }
    }

    CvKNearest kNN;
    kNN.train(training_data, class_labels);
    kNN.find_nearest(validation_data, 3, &prediction_results);

    for(int i = 0; i < NUM_VALIDATION_EXAMPLES; ++i)
    {
        float prediction = prediction_results.at<float>(i, 0);
        cout << prediction << " " << correct_results[i] << "\n";
    }

    return 0;
}
