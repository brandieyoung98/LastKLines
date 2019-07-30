#include <iostream>
#include <sstream>
using namespace std;

//yields the index of the nth occurence of character c in the string s
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

void printLastKLines(int k){
	string line = "";
	string fileText = "";
	int numLines = 0;
	while(!getline(cin, line).eof()){
	    numLines++;
	    fileText += line + '\n';
	}
	numLines++;
	fileText += line; //get that last line
	
	if(k == numLines){
	   cout << fileText << endl; 
	}
	else if(k <= 0 || k > numLines || fileText.empty()){
	    cout << "Invalid input" << endl;
	}
	else{
	    int lineBreak = numLines - k;
	    string lastKLines = fileText.substr(findNthCharOccurence(lineBreak, '\n', fileText));
	    cout << lastKLines << endl;
	}
}

int main(){
    printLastKLines(4);
    return 0;
}
	
