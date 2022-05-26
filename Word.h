#ifndef Word_H
#define Word_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Word {

 private:
	string word;
	int numAppearances;

 public:
	Word(const string &);
	void addNewAppearance();
	const string & getWord();
  int getCount();
};
#endif