/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    vector<string> wordList;
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile, word)) {
        wordList.push_back(word);
      }
    }
    for(string origWord : wordList){
      string sortChar = origWord;
      std::sort (sortChar.begin(), sortChar.end());
      auto lookup = dict.find(sortChar);
      if(lookup == dict.end()){
        //if this pair does not exist in the dictionary yet
        std::vector<string> v;
        v.push_back(origWord);
        dict.insert(std::pair<string,vector<string>>(sortChar,v));
      }
      else{//if this pair already exists, then push the new anagram(this word) into the vector list
        lookup->second.push_back(origWord);
      }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for(string origWord : words){
      string sortChar = origWord;
      std::sort (sortChar.begin(), sortChar.end());
      auto lookup = dict.find(sortChar);
      if(lookup == dict.end()){
        //if this pair does not exist in the dictionary yet
        std::vector<string> v;
        v.push_back(origWord);
        dict.insert(std::pair<string,vector<string>>(sortChar,v));
      }
      else{//if this pair already exists, then push the new anagram into the vector list
        lookup->second.push_back(origWord);
      }
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string sortChar = word;
    std::sort(sortChar.begin(),sortChar.end());
    auto lookup = dict.find(sortChar);
    if(lookup == dict.end()){
      return vector<string>();
    }
    else{
      if(lookup->second.size()>1){
        return lookup->second;
      }
      else{
        return vector<string>();
      }
    }
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> retval;
    for(auto& origWord : dict){
     vector<string> anagramWord = get_anagrams(origWord.first);
     if(anagramWord.size()!=0){
       retval.push_back(anagramWord);
     }
   }
    return retval;
}
