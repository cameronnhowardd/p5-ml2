#include <cassert>
#include <cstddef>
#include <iostream>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include "csvstream.hpp"


std::set<std::string> unique_words(const std::string &str) {
  std::istringstream source(str);
  std::set<std::string> words;
  std::string word;
  while (source >> word) {
    words.insert(word);
  }
  return words;
}

class Classifier {

private:
struct DataSet {
int totalPosts;
int totalUniqueWords;
std::set<std::string> UniqueWords;
std::map<std::string, int> numForEachWord;
std::map<std::string, int> numForEachLabel;
std::map<std::string, std::map<std::string, int> > numPairWordLabel;
};



public:

Classifier();
~Classifier();

DataSet training(std::string filename) {
    csvstream csv_file(filename);
    std::map<std::string, std::string> row;
    DataSet dataset;
    dataset.totalPosts = 0; 
    while(csv_file >> row){
        dataset.totalPosts++;
        std::string labelOfPost = row["C"];
        dataset.numForEachLabel[labelOfPost]++;
        std::set<std::string> setOfUniqueWords = unique_words(row["w"]);
        for (const std::string &uniqueWord : setOfUniqueWords) {
             dataset.totalUniqueWords.insert(uniqueWord);
             dataset.numPairWordLabel[labelOfPost][uniqueWord]++;
        }
    }
    return dataset;
}
double probability(std::string filename, const std::string &word, const std::string &label) {
csvstream csv_file(filename);
std::string C;
DataSet dataset;
DataSet datum = training(filename);
double logProb = 0.0;
int labels = dataset.numForEachLabel[C];
for (const auto &word : words){
if(dataset.numForEachLabel.find(word) != dataset.numForEachLabel.end()){
    double logPrior = std::log(static_cast<double>(labels)/dataset.totalPosts);
    logProb += logPrior;
}
else if (dataset.numPairWordLabel[C].find(word) != dataset.numPairWordLabel[C].end()){
    double logPrior = std::log(static_cast<double>(dataset.numPairWordLabel[C][word])/dataset.numForEachLabel[C]);
    logProb += logPrior;
}
else if (//Use when does not occur in posts labeled but does occur in the training data overall.)
{
    double logPrior = std::log(static_cast<double>(dataset.numForEachWord[word])/dataset.totalPosts);
    logProb += logPrior;
}
else {
    double logPrior = std::log(static_cast<double>(1)/dataset.totalPosts);
    logProb += logPrior;
}
}
return logProb;
}


std::pair<std::vector<std::set<std::string> >, std::vector<std::string> > highestprobability(std::set<std::string> uniques) const{
    std::string best;
    double highestScore = -std::numeric_limits<double>::infinity();
    for (const auto &word : words) {
    double score = probability(filename);
    if (score > highestScore){
        highestScore = score;
        best = score.label;
    }
    return best;
  }
}
std::string prediction(std::string filename){
    csvstream predictionStream(filename);
    std::map<std::string, std::string> piazza;

    while (predictionStream >> piazza){
        DataSet data;
        data.UniqueWords = unique_words(piazza["post"]);
        std::string theLabel = highestprobability(data.UniqueWords);
}
return theLabel;
}

};



int main(int argc, char *argv[]){
std::cout.precision(3);
    if ((argc != 3) && (argc != 4)) {
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
    }
    if ((argc == 4) && strcmp(argv[3], "--debug") != 0){
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
  }

  bool debug = (argc == 4) && (std::string(argv[3]) == "--debug");

Classifier classifier;
classifier.training(argv[1]);
if (debug){

}

}