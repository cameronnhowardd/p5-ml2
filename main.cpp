#include <cassert>  //assert
#include <iostream> //ostream
#include <functional> //less
#include <utility>
#include <map>
#include <set>
#include "csvstream.hpp"
// 1) read csv 
// 2) read each sentence in the csv 2a. break that sentence  down into unique words 
// 2b. Each set of those words is assigned a label (should be in the csv entry for that sentence)
// function main(arguments):
int main(int argc, char *argv[]){
    if ((argc != 3) && (argc != 4)) {
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
    }
    if ((argc == 4) && strcmp(argv[3], "--debug") != 0){
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
  }
  std::string exname = argv[0];
  std::string file1 = argv[1];
  std::string file2 = argv[2];
  std::string debug = argv[3];


  std::string filename = "argv[1]";
  std::ifstream fin;
  fin.open(file1);
  if (!fin.is_open()) {
    std::cout << "Error opening file: " << filename << std::endl;
    return 1;
  }

  std::string filename2 = "argv[2]";
  std::ifstream fin2;
  fin.open(file2);
  if (!fin.is_open()) {
    std::cout << "Error opening file: " << filename << std::endl;
    return 1;
  }
//     trainingFile, testFile, debugMode = parseArguments(arguments)

//     // Initialize your classifier
//     classifier = new Classifier()
class Classifier {

Classifier(){
}

~Classifier(){
}

void initializeData(std::istream& in) {

}
void debuggerData(std::istream& in) {

}
void predictionsData(std::istream& in){

}

void evaluatePredicationsData(std::istream& in){

}

void performanceData(std::istream& in){

}
};
//     // Load and train the classifier
//     trainingData = readDataFromFile(trainingFile)
//     classifier.train(trainingData)

//     // If debug mode is active, print additional debug information
//     if debugMode:
//         classifier.printDebugInfo()

//     // Perform predictions on the test data
//     testData = readDataFromFile(testFile)
//     predictions = classifier.predict(testData)

//     // Evaluate and print the predictions
//     printPredictions(predictions)

//     // Optionally, print the performance of the classifier
//     printPerformance(predictions, testData)

//     return success

// // Supporting functions (readDataFromFile, printDebugInfo, etc.)
}