# Gender Classification From Facial Images

## Dataset
The [nottingham_scans](http://pics.psych.stir.ac.uk/zips/nottingham.zip) database has been used in this project. It contains images of 50 males and 50 females in neutral, frontal pose.

## Feature Extraction
Spatially enhanced uniform pattern LBP histograms have been used as features in this project. The code for extracting features from the cropped and aligned facial images resides in the ``` lbp-features-code ``` folder. The code from this [Github repository](https://github.com/bytefish/opencv/tree/master/lbp) has been used as a reference and several additional methods havebeen added.
Specifically, methods for detecting uniform pattern codes and a main function (named ``` lbp_features.cpp ```) for calculating the LBP histogram features of the input image have been added.
The feature vectors for all of the 100 images in the database reside in the ``` features ``` folder. The length of the feature vectors is 531. The file ``` lbp_features.txt ``` contains the feature vectors with th elast column of each line denoting the class label (0 = female, 1 = male).

Refer to the report (``` Report.pdf  ```) for any additional information!

## Classifiers
The following classification algorithms have been applied to the dataset:
+ Naive Bayes: ``` naive-bayes.r  ``` is the R-script for running the naive Bayes classifier on the feature vectors.
+ k-Nearest Neighbors: The file ``` knn.cpp  ``` contains the [OpenCV implementation](http://docs.opencv.org/modules/ml/doc/k_nearest_neighbors.html) of the k-NN algorithm applied to the feature vectors.
+ Neural Networks: ``` neural-net.r  ``` is the R-script for Neural Networks.
+ Support Vector Machines: The file ```  svm.cpp ``` contains the [OpenCV implementation](http://docs.opencv.org/modules/ml/doc/support_vector_machines.html) of an SVM classifier applied to our problem.

## Contributors
+ [Samyak Datta](https://github.com/samyak-268/)
+ [Abhishek K. Das](https://github.com/AbKDs)



