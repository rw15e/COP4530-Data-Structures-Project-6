// Assignment 6 COP4530
// Ryan Winter
// 12/7/17 (Fall 2017)

#include <iostream>
#include <iomanip> // needed for setw
#include <string>
#include <map>
#include <vector>

using namespace std;

void printChr(std::map<string, pair<int, int>> &map, int loopCount);  // prints out top 10 characters
void printWord(std::map<string, pair<int, int>> &map, int loopCount); // prints out top 10 words
void printNumber(std::map<string, pair<int, int>> &map, int loopCount);  // prints out top 10 numberbers

int main(){
	// The first int of pair holds the number of times the item is found and the second int in pair holds its insertion order number
	std::map<string, pair<int, int>> cMap; // map of characters
	std::map<string, pair<int, int>> wMap; // map of words
	std::map<string, pair<int, int>> nMap; // map of numbers
	
	char chr; // temporarily holds each character read in
	string character; // holds each character read in
	string word; // holds each word read in
	string number; // holds each number read in
	int count = 0; // counts number of characters (number of times while loop is run)
	int wCount = 0; // counts number of words 
	int nCount = 0; // counts number of numbers
	
	while(!cin.eof()){ // run until reaches EOF
		count++;
		cin.get(chr); // get input one char at a time
		character += chr; // append chr to character in every iteration of loop
		
		if(cin.fail() == true){	// fixes issue of missing "bb" on test0
			if(word.size() >= 1){
				if(wMap.find(word) == wMap.end()){
					wMap.insert(make_pair(word, make_pair(1, count)));
					wCount++;
				}
				else
					++wMap[word].first;
				word = ""; // need to reset temp variable
			}
			else if(number.size() >= 1){
				if(nMap.find(number) == nMap.end()){
					nMap.insert(make_pair(number, make_pair(1, count)));
					nCount++;
				}
				else
					++nMap[number].first;
				number = ""; // need to reset temp variable
			}
			break; // fixes issue of reading in one too many EOF
		}
		else if(isdigit(chr) != 0){ // check if chr is a digit (0-9)
			number += chr;
			if(word.size() >= 1){
				if(wMap.find(word) == wMap.end()){
					wMap.insert(make_pair(word, make_pair(1, count)));
					wCount++;
				}
				else
					++wMap[word].first;
				word = ""; // need to reset temp variable
			}
		}
		else if(isalpha(chr) != 0){ // check if chr is alphabetic (a-z)
			word += tolower(chr);
			if(number.size() >= 1){
				if(nMap.find(number) == nMap.end()){
					nMap.insert(make_pair(number, make_pair(1, count)));
					nCount++;
				}
				else
					++nMap[number].first;
				number = ""; // need to reset temp variable
			}
		}
		else{ // check if chr is not a digit or alphabetic
			if(word.size() >= 1){
				if(wMap.find(word) == wMap.end()){
					wMap.insert(make_pair(word, make_pair(1, count)));
					wCount++;
				}
				else
					++wMap[word].first;
				word = ""; // need to reset temp variable
			}
			else if(number.size() >= 1){
				if(nMap.find(number) == nMap.end()){
					nMap.insert(make_pair(number, make_pair(1, count)));
					nCount++;
				}
				else
					++nMap[number].first;
				number = ""; // need to reset temp variable
			}
		}
		++cMap[character].first;
		character = ""; // need to reset temp variable
	} // end of loop 


    printChr(cMap, count);
    printWord(wMap, wCount);
	printNumber(nMap, nCount);

	return 0;
}

void printChr(map<string, pair<int, int>> &map, int loopCount){
	int counter = 0;
    std::map<string, pair<int, int>>::iterator temp = map.begin();
	
	if(loopCount > 10)
		loopCount = 10;
	
	if(loopCount > map.size())
		loopCount = map.size();

	cout << "Total "<< map.size() << " different characters, " << loopCount << " most used characters:" << endl;
	for(int i = 0; i < loopCount; i++){
		int value = 0; // need to reset back to 0 at every iteration to ensure it doesnt hold old data

		for(std::map<string, pair<int, int> >::iterator it = map.begin(); it != map.end(); ++it){
			 if(it->second.first > value || (it->second.first == value && (it->second.second < temp->second.second))){
				value = it->second.first;
				temp = it;
				counter++;
			}
		}
		cout << "No. " << i << ": ";
		if(temp->first == "\t")
			cout << "\\t" << "		" << value << endl;
		else if(temp->first == "\n")
			cout << "\\n" << "		" << value << endl;
		else
			cout << temp->first << "		" << value << endl;
		map.erase(temp); // need to remove otherwise it will keep pulling same value
	}
}				

void printWord(map<string, pair<int, int>> &map, int loopCount){
    int counter = 0;
	std::map<string, pair<int, int>>::iterator temp = map.begin();
	
	if(loopCount > 10)
		loopCount = 10;
	
	if(loopCount > map.size())
		loopCount = map.size();
	
	cout << endl << "Total "<< map.size() << " different words, " << loopCount << " most used words:" << endl;
	for(int i = 0; i < loopCount; i++){
		int value = 0; // need to reset back to 0 at every iteration to ensure it doesnt hold old data

		for(std::map<string, pair<int, int>>::iterator it = map.begin(); it != map.end(); ++it){
			if(it->second.first > value || (it->second.first == value && (it->second.second < temp->second.second))){
				value = it->second.first;
				temp = it;
				counter++;
			}
		}
		cout << "No. " << i << ": " << temp->first << "		" << value << endl;
		map.erase(temp); // need to remove otherwise it will keep pulling same value
	}
}				

void printNumber(map<string, pair<int, int>> &map, int loopCount){
	int counter = 0;
	std::map<string, pair<int, int>>::iterator temp = map.begin();

	if(loopCount > 10)
		loopCount = 10;  
	
	if(loopCount > map.size())
		loopCount = map.size();
	
	cout << endl << "Total "<< map.size() << " different numbers, " << loopCount << " most used numbers:" << endl;
	for(int i = 0; i < loopCount; i++){
		int value = 0; // need to reset back to 0 at every iteration to ensure it doesnt hold old data

		for(std::map<string, pair<int, int> >::iterator it = map.begin(); it != map.end(); ++it){
			if(it->second.first > value || (it->second.first == value && (it->second.second < temp->second.second))){
				value = it->second.first;
				temp = it;
				counter++;
			}
		}
		cout << "No. " << i << ": " << temp->first << "		" << value << endl;
		map.erase(temp); // need to remove otherwise it will keep pulling same value
	}
}
