#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include "Word.h"
using namespace std;

class HashTable {

 private:
	list<Word> *hashTable;
	int size;

 public:
	HashTable(int s);
	bool contains( string );
	void put(string s);
int getCount(string s);
 
 private:
	int computeHash(const string &);
};

#endif