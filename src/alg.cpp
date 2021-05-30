// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  char Dif = 'a' - 'A';
  std::string word = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "There is no file" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char sym = file.get();
    if ((ch >= 'a' && ch <= 'z') || (sym >= 'A' && ch <= 'Z')) {
      if (sym >= 'A' && ch <= 'Z') sym += Dif;
      word += sym;
    } else if (word != "") {
      Tree.add(word);
      word = "";
    }
  }
  file.close();
  return Tree;
}
