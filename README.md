# Machine-Learning-Assignment
Given 30k datapoints of technical skills and jargon in the Raw_Skills_Database.csv file, I used 900 examples of technical skills given in the Example_Technical_Skills.csv file to filter out and extract hard skills from the Raw_Skills_Database.csv file and stored it in the Extracted_Technical_Skills.csv file.

Step 1 Initialize Hashtable to store Data

I created a HashTable, implemented using lists, to store all the data from the Example_Technical_Skills.csv. By using a HashTable to store all of the values over another data structure such as a vector, I can more efficiently search through it as HashTables have a Big-O complexity of O(1), while vectors are O(N). 

Step 2 Input Technical Skills

Next I go through the Example_Technical_Skills.csv, taking in one line from the file at a time. I store the line in a string, then search through it for a space or a slash in order to separate the words. I filter out all “-”, “&”, and “and” words as those words aren’t skills on their own, but connect technical words. I then initialize a word object containing the string and insert that into the HashTable. I used word objects to better store the string along with a counter that represents how many times that word appears in the Example_Technical_Skills.csv file. When storing the words into my HashTable, I stored it as uppercase to prevent uppercase and lowercase words from counting as completely separate words and having separate appearance counters.

Step 3 Check Raw Skills

Next I go through the data from the Raw_Skills_Database.csv. I take one line at a time and store it into a string. I loop through the string, taking one word at a time as I did in Step 1. I search through the HashTable for the word and if it appears in the HashTable, I add its number of appearances to an appearances variable that stores the total number of appearances of each word in the sentence. I go through each word of the sentence, storing the total appearances and the number of words. I divide the total appearances by the number of words in the sentence to get the average number of appearances per word in the sentence. If that average is above 0.5, then I outputted it into the new Extracted_Technical_Skills.csv file. I chose an average of 0.5 because it filters out all skills that weren’t mentioned in the Example_Technical_Skills.csv file. I also noticed many soft skills were receiving scores below 0.5.
