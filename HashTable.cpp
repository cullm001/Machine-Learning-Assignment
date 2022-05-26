#include "HashTable.h"
#include "Word.h"
#include <array>
#include <list>
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

HashTable::HashTable (int s) {
	size = s;
  hashTable = new list<Word>[s];
}



int HashTable::computeHash(const string &s) {
  int total = 0;
  for (unsigned i = 0; i < s.size(); ++i){
    total += pow(32,i) *  s[i];
  }
  total %= size;
  if(total<0){
    total *=-1;
  }
  return total;
}


void HashTable::put( string s) {
  s[0] = toupper(s[0]);
  if (!contains(s)) {
    int index = computeHash(s);
    list<Word> *indexPtr= &hashTable[index];
    Word entry = Word(s);
    indexPtr->push_back(entry);
    
  }
  else{
    int index = computeHash(s);
    list<Word> *indexPtr = &hashTable[index];
    list<Word>::iterator i;
    for(i = indexPtr->begin(); i!=indexPtr->end(); i++){
      if(i->getWord() == s){
        i->addNewAppearance();
      }
    }
  }
}

 int HashTable::getCount( string s){
   if (!contains(s)){
     return 0;
   }
   s[0] = toupper(s[0]);
   int index = computeHash(s);
    list<Word> *IndexPtr= &hashTable[index];
    list<Word>::iterator i;
   for (i = IndexPtr->begin(); i!=IndexPtr->end(); i++){
      if ( strcasecmp(i->getWord().c_str(), s.c_str()) == 0){
        
        return i->getCount();
      }
   }
 }

bool HashTable::contains( string s) {
s[0] = toupper(s[0]);
  bool in = false;
  int index = computeHash(s);
  list<Word> *indexPtr = &hashTable[index];
  list<Word>::iterator i;
  for(i = indexPtr->begin(); i!=indexPtr->end(); i++){
    if(strcasecmp(i->getWord().c_str(), s.c_str()) == 0){
      in = true;
    }
  }
  return in;
}

