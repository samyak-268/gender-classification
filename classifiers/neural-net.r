library(neuralnet)

formula = "V532 ~ "
for (i in 1:(ncol(lbpdata)-2)) {
    formula <- paste(formula, "V", toString(i), "+", sep = "")
}

formula <- paste(formula, "V", toString(ncol(lbpdata)-1), sep = "")

for (i in 1:5) { # for 5 folders
    wd <- getwd()
    dir <- "/home/abkds/gender-classification/features/five-cross-validation/fold-"
    dir <- paste(dir, toString(i), "/", sep = "")
    setwd(dir)
    
    lbpdata <- read.table("train.txt")
    lbppredict <- read.table("validation.txt")   
    
    net.genderclassifier <- neuralnet(formula ,lbpdata, hidden = c(50, 20),
                                linear.output = FALSE, threshold=0.007)
    results <- compute(net.genderclassifier, lbppredict[, -532])
    output <- results$net.result
    output[output < 0.5] = 0
    output[output > 0.5] = 1
    
    predictions <- cbind(lbppredict[, 532], output, results$net.result)
    
    writedir <- "/home/abkds/gender-classification/results/neural-net/"
    filename <- paste(writedir, "neural-net-", toString(i), ".txt", sep = "")
    write.table(predictions, file = filename, row.names = FALSE
                , col.names = FALSE)
    setwd(wd)
}