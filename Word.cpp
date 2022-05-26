#include "Word.h"

Word::Word(const string &text)
 : word(text), numAppearances(1) {
}

void Word::addNewAppearance() {
	++numAppearances;
}

int Word::getCount(){
  return numAppearances;
}

const string & Word::getWord() {
    return word;
}

