#include <iostream>
#include <sstream>
using namespace std;

//helper method that yields the index in string s of the nth occurence of character c
int findNthCharOccurence(int n, char c, string s){
    int count = 0;
    for(int i = 0; i< s.size(); i++){
        if(s.at(i) == c){
            count++;
            if(count == n){
                return i;
            }
        }
    }
    return -1; //error, said char was not found
}
//desired function that prints the last k lines based off user input
void printLastKLines(int k){
	string line = "";
	string fileText = "";
	int numLines = 0;
	//reading in all input and counting the lines
	while(!getline(cin, line).eof()){
	    numLines++;
	    fileText += line + '\n';
	}
	numLines++;
	fileText += line; //account for that last line
	
	if(k == numLines){ //this means the whole input
	   cout << fileText << endl; 
	}
	else if(k <= 0 || k > numLines || fileText.empty()){ //impossible k or no user input
	    cout << "Invalid input" << endl; //error message
	}
	else{
	    int lineBreak = numLines - k; //the line number where we need to print from
	    string lastKLines = fileText.substr(findNthCharOccurence(lineBreak, '\n', fileText)); //"break off" just the last k lines
	    cout << lastKLines << endl; // and print em!
	}
}
//testing in the main method
//to test, change up the k value passed to the method and the user input of course
int main(){
    printLastKLines(4);
    return 0;
}
	
