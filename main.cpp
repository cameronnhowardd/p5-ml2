#include <cassert>  //assert
#include <cstddef>
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
std::set<std::string> unique_words(const std::string &str) {
  std::istringstream source(str);
  std::set<std::string> words;
  std::string word;
  while (source >> word) {
    words.insert(word);
  }
  return words;
}
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
  //std::string debug = argv[3];

  



//     trainingFile, testFile, debugMode = parseArguments(arguments)

//     // Initialize your classifier
//     classifier = new Classifier()
class Classifier {

Classifier(){
}

~Classifier(){
}
std::pair<std::vector<std::set<std::string> >, std::vector<std::string> > myFunction(std::string filename) {
    std::ifstream file(filename); // Open the CSV file
    if (!file.is_open()) {
        std::cerr << "Error opening file:" << filename << std::endl;
    }

//   std::string filename2 = "argv[2]";
//   std::ifstream fin2;
//   fin.open(file2);
//   if (!fin.is_open()) {
//     std::cout << "Error opening file: " << filename << std::endl;
//     return 1;
//   }

    std::string line;
    std::getline(file, line);
    std::vector<std::string> *strings = new std::vector<std::string>;
    std::vector<std::set<std::string> > *sets = new std::vector<std::set<std::string> >;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string *token = new std::string;
        std::string *tag = new std:: string;  // String to store the third entry
        // Iterate to get the third entry
        for (int i = 0; i < 3 && std::getline(ss, *token, ','); ++i) {
            if (i == 2) {
                *tag = *token;
                break;  // Exit the loop after the third entry
            }
        }

    std::cout << tag << std::endl;
    std::string cell;
    //std::cout << line << std::endl;
    std::getline(ss, *token, ',');
    std::set<std::string> x = unique_words(*token);
    // Print all elements in the set
    for (const auto& element : x) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    sets.push_back(x);

    strings -> push_back(token);
    }
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