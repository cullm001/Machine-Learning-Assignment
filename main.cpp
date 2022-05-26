#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	string line;    
	int score;
	string message;
	

	ifstream myfile("Example_Technical_Skills.csv");
	if (myfile.fail()) {
	    cout << "could not open file" << endl;
	    exit(1);
	}
	
	
	HashTable table(20071);
  int c = 0;
  line.clear();
  string g;
  getline(myfile, line);
	while ( getline(myfile, line)) {
	    int len = line.size();
	    while(len > 0) {     
	        string sub;
          if (line.find("/") < line.find(" "))
	          len = line.find("/");
          else
            len = line.find(" ");
	        if (len > 0) {
	            sub = line.substr(0, len);
	            line = line.substr(len + 1, line.size());
	        }
	        else {
	            sub = line;
	        }
        if (sub != "-" && sub != "&" && sub != "and")
	        table.put(sub); 
        
       
          
	    }
	}

  ofstream outFS("Extracted_Technical_Skills.csv");
  ifstream allSkills("Raw_Skills_Dataset.csv");
  int first = 0;

  getline(allSkills, message);
  while ( getline(allSkills, message) ){
    
	    double appearances = 0;
       double numWords = 0;
	    
	    double totalScore = 0.0;
	    string temp = message.substr(0,message.size()-1);
	    int len = message.size();
	    while(len > 0) {
	        string sub;
	        if (message.find("/") < message.find(" "))
	          len = message.find("/");
          else
            len = message.find(" ");
	        if (len > 0) {
	            sub = message.substr(0, len);
	            message = message.substr(len + 1, message.size());
	        }
	        else {
	            sub = message.substr(0,message.size()-1);
	        }
       
     appearances += table.getCount(sub);
        
           numWords++;
         
	    }
    
       totalScore = appearances/numWords;
   
	    if (message.size() > 0 && totalScore > .5) {
         outFS << temp << " " << totalScore << endl;
	      }
 
    }
    
	return 0;
}
