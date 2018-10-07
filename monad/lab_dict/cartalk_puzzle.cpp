/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    /* Your code goes here! */
    vector<string> wordList;//create a list to put in all 5-letter words
    ifstream wordsFile(word_list_fname);
    string word;
    //read in dictionary, get in all 5-letter words
    if (wordsFile.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile, word)) {
        if(word.length()==5){
          wordList.push_back(word);
        }
      }
    }
    vector<StringTriple> retval;
    //get the first and second removed from the 5-letter word;
    for(size_t i = 0;i<wordList.size();i++){
      string origWord = wordList[i];
      string first = wordList[i].substr(1);
      string second = wordList[i].substr(0,1);//the first letter of the 5-letter word;
      string rest = wordList[i].substr(2);
      second.append(rest);

      //compare if they are homophones to the original word
      if(d.homophones(origWord,first)&&d.homophones(origWord,second)){
        StringTriple wordPair;
        std::get<0>(wordPair) = origWord;
        std::get<1>(wordPair) = first;
        std::get<2>(wordPair) = second;
        retval.push_back(wordPair);
      }
    }
    return retval;
}
