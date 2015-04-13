library(class)
library(e1071)

for (i in 1:5) {  # for 5 folders
    wd <- getwd()
    dir <- "/home/abkds/gender-classification/features/five-cross-validation/fold-"
    dir <- paste(dir, toString(i), "/", sep = "")
    setwd(dir)
    
    lbpdata <- read.table("train.txt")
    lbppredict <- read.table("validation.txt")   
    
    lbpdata$V532 <- as.factor(lbpdata$V532)
    lbppredict$V532 <- as.factor(lbppredict$V532)
    
    classifier <- naiveBayes(lbpdata[, 1:531], lbpdata[, 532])
    predictions <- as.data.frame(cbind(as.integer(as.character(lbppredict[, 532]))
                , as.integer(as.character(predict(classifier,lbppredict[, -532])))))    
    
    writedir <- "/home/abkds/gender-classification/results/naive-bayes/"
    filename <- paste(writedir, "naive-bayes-", toString(i), ".txt", sep = "")
    write.table(predictions, file = filename, row.names = FALSE
                , col.names = FALSE)
    setwd(wd)
}