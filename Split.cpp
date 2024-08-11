#include <iostream>
#include <string>

const int SPACE = 32;
const int COMMA = 44;
const int PERIOD = 46;

std::string* createWordsArray(std::string sentence, int& outWordsArraySize) {
  int str_len = sentence.length();
  int cursor = 0;
  std::string word;
  char elem;
  std::string* word_bin = new std::string[str_len];
  for (int idx = 0; idx < str_len; idx++) {
      elem = sentence[idx];
      if (elem == SPACE || elem == COMMA || elem == PERIOD || idx == str_len - 1) {
          if (idx == str_len - 1)
              idx++;
          word = sentence.substr(cursor, idx - cursor);
          if (word.length())
              word_bin[outWordsArraySize] = word;
          cursor = idx + 1;
          outWordsArraySize++;
      }
  }

  std::string* slim_bin = new std::string[outWordsArraySize];
  for (int idx = 0; idx < outWordsArraySize; idx++)
      slim_bin[idx] = word_bin[idx];
  
  delete [] word_bin;

  return slim_bin;
}

void print_arr(std::string* word_arr, int word_cnt) {
  std::cout<<word_cnt<<" words:"<<std::endl;
  std::cout<<word_arr[0];
  for (int idx = 1; idx < word_cnt; idx++)
      std::cout<<", "<<word_arr[idx];
  std::cout<<std::endl;
}

int main() {
  std::string sentence;
  std::cout<<"Please enter a sentence:"<<std::endl;
  std::getline(std::cin, sentence);
  
  int word_cnt = 0;
  std::string* word_arr = createWordsArray(sentence, word_cnt);

  print_arr(word_arr, word_cnt);
  
  delete [] word_arr;
  
  return 0;
}
