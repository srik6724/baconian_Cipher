#include <iostream>  
#include <stdio.h> 
#include <fstream>
#include <string.h>
const char* chartoBacon(char);
char bacontoEnglish(const char*); 
/*

Author: Srikar Balasubramanian

Date: 10/19/2022

Description: The graded portion of this assignment will have you processing a code inspired by 
Francis Bacon’s Cipher.  You will work with command line arguments and file I/O 
to process English characters into cipher patterns and back into English. 
The ungraded portion will get you used to working with the Unix/Linux compiler 
through some exercises and introduce the gdb debugger. 

Usage: <exe> <infile> <-bc|-e> <outfile>

*/
using namespace std; 
int main(int argc, char** argv)  {
	
	//ifstream and ofstream declared here to take in input and output.
	ifstream inFile; 
	char buffer[255]; 
	ofstream outfile;  
	//Command line arguments are used here to open input file and output file.
	//input file: ./ the executable
	//output file: the file you want your data to be stored in.
	inFile.open(argv[1]); 
	outfile.open(argv[3]); 
	
	//Check for Error
	//If the file cannnot be opened due to some random error, it will print this message out. 
	if (inFile.fail()) {
		cout << "There was an error in opening your file." << endl; 
		exit(1); 
	}
	//This is a helpful message to show how command line arguments were entered. 
	cout << "The user has entered " << argc
		<< " arguments:" << '\n'; 
		//This checks if the number of command line arguments is the right number. 
		//If it is, then it proceeds to check whether it should convert to bacon code or english -bc, or -e
	if(argc < 4) {
		cout << "Error: You have less than 4 command line arguments." << endl; 
		return 0; 
	}else if(strcmp(argv[2], "-bc") == 0) {
	 //Message to begin translation is printed. 
	 cout << "Translating " << argv[1] << argv[2] << " to BACON code." << endl; 	
		//Gets every line from the input file using a buffer of max 255 characters. 
		while(inFile.getline(buffer, 255)) {
			//Loops through the buffer and outputs every character into BACON code. 
			for(int i = 0; i < strlen(buffer); i++) {
				if(i == strlen(buffer) - 1) {
					//Output of bacon code is received and data is stored in outfile. 
					outfile << chartoBacon(buffer[i]); 
				}else{
					//For every letter until the last one, it will append the "|" as well. 
					outfile << chartoBacon(buffer[i]) << "|"; 
				}
			}
			outfile << "\n"; 
			//Goes to the next line in the input file. 
		}
		cout << argv[1] << " completed." << endl;
		//Message that it's completed with the format that it is printed in. 
		outfile.close(); 
		inFile.close();
		//file is directly closed after for outfile and infile. 
	}else if(strcmp(argv[2], "-e") == 0) {
		char anotherbuffer[1530]; 
		char* token; 
		cout << "Translating " << argv[1] << argv[2] << " to BACON code." << endl; 	
		//Gets every line from the input file using a buffer of max 1530 characters. 
		while(inFile.getline(anotherbuffer, 1530)) {
			//Gets the token by tokenizing using strtok. 
			//Basically, gets every linss from the buffer 
			//and tokenizes with delimiter of "|\n"
			token = strtok(anotherbuffer, "|\n"); 
			//Terminating condition for if there are tokens left to read from the buffer. 
			while(token != NULL) {
				outfile << bacontoEnglish(token); 
				token = strtok(NULL, "|\n"); 
				//Will move to the next token by using a delimiter of "|\n"
			}
			//Next line is added, basically implying it moves to next line of buffer. 
			outfile << "\n"; 
		}
		//Message that it's completed with the format that it is printed in. 
		cout << argv[1] << " completed." << endl; 
		//outFile and inFile are closed.
		outfile.close(); 
		inFile.close(); 
	}
}

//First function that indicates the charToBacon conversion
//from English to bacon code. 
//Return type is const char*
//There are 26 cases respectively and it takes into account lowercase and uppercase letters.
//Then returns the value based on the BACONCODE alues that it matches to. 
//default case in this is !1!!! if there is no space or letter to read in the buffer. 
const char* chartoBacon(char character) {
	switch(character) {
		case 'a': 
		case 'A': 
			return "aaaaa"; 
		case 'b': 
		case 'B': 
			return "aaaab"; 
		case 'c': 
		case 'C': 
			return "aaaba"; 
		case 'd': 
		case 'D': 
			return "aaabb"; 
		case 'e': 
		case 'E': 
			return "aabaa"; 
		case 'f': 
		case 'F': 
			return "aabab"; 
		case 'g': 
		case 'G': 
			return "aabba"; 
		case 'h': 
		case 'H': 
			return "aabbb"; 
		case 'i': 
		case 'I': 
			return "abaaa"; 
		case 'j': 
		case 'J': 
			return "abaab"; 
		case 'k': 
		case 'K': 
			return "ababa"; 
		case 'l': 
		case 'L': 
			return "ababb"; 
		case 'm': 
		case 'M': 
			return "abbaa"; 
		case 'n': 
		case 'N': 
			return "abbab"; 
		case 'o': 
		case 'O': 
			return "abbba"; 
		case 'p': 
		case 'P': 
			return "abbbb";
		case 'q': 
		case 'Q': 
			return "baaaa"; 
		case 'r': 
		case 'R': 
			return "baaab"; 
		case 's': 
		case 'S': 
			return "baaba"; 
		case 't': 
		case 'T': 
			return "baabb"; 
		case 'u': 
		case 'U': 
			return "babaa"; 
		case 'v': 
		case 'V': 
			return "babab"; 
		case 'w': 
		case 'W': 
			return "babba"; 
		case 'x': 
		case 'X': 
			return "babbb"; 
		case 'y': 
		case 'Y': 
			return "bbaaa"; 
		case 'z': 
		case 'Z': 
			return "bbaab"; 
		case ' ': 
			return "/";
		case '|': 
			return ""; 
		default: 
			return "!!!!!"; 
	}
	}
//Second function that indicates baconCode to English conversion. 
//Return value is a char with const char* parameter. 
//There are 26 cases respectively and uses strcmp to compare two strings and return respective char. 
//Then returns the english value based on the BACONCODE value that it matches to. 
//default case in this is E if there is no BACONCODE value to read or no "/" to read as well.
//Hence, !!!!! will be returned. 
char bacontoEnglish(const char* character) {
	if(strcmp(character, "aaaaa") == 0) {
		return 'A'; 
	}else if(strcmp(character, "aaaab") == 0) {
		return 'B'; 
	}else if(strcmp(character, "aaaba") == 0) {
		return 'C'; 
	}else if(strcmp(character, "aaabb") == 0) {
		return 'D'; 
	}else if(strcmp(character, "aabaa") == 0) {
		return 'E'; 
	}else if(strcmp(character, "aabab") == 0) {
		return 'F'; 
	}else if(strcmp(character, "aabba") == 0) {
		return 'G'; 
	}else if(strcmp(character, "aabbb") == 0) {
		return 'H'; 
	}else if(strcmp(character, "abaaa") == 0) {
		return 'I'; 
	}else if(strcmp(character, "abaab") == 0) {
		return 'J'; 
	}else if(strcmp(character, "ababa") == 0) {
		return 'K'; 
	}else if(strcmp(character, "ababb")== 0) {
		return 'L'; 
	}else if(strcmp(character, "abbaa")== 0) {
		return 'M'; 
	}else if(strcmp(character, "abbab")== 0) {
		return 'N'; 
	}else if(strcmp(character, "abbba")== 0) {
		return 'O'; 
	}else if(strcmp(character, "abbbb")== 0) {
		return 'P'; 
	}else if(strcmp(character, "baaaa") == 0) {
		return 'Q'; 
	}else if(strcmp(character, "baaab") == 0) {
		return 'R'; 
	}else if(strcmp(character, "baaba") == 0) {
		return 'S'; 
	}else if(strcmp(character, "baabb") == 0) {
		return 'T'; 
	}else if(strcmp(character, "babaa") == 0) {
		return 'U'; 
	}else if(strcmp(character, "babab") == 0) {
		return 'V'; 
	}else if(strcmp(character, "babba") == 0) {
		return 'W'; 
	}else if(strcmp(character, "babbb") == 0) {
		return 'X'; 
	}else if(strcmp(character, "bbaaa") == 0) {
		return 'Y'; 
	}else if(strcmp(character, "bbaab")== 0) {
		return 'Z'; 
	}else if(strcmp(character, "/") == 0) {
		return ' '; 
	}else if(strcmp(character, "!!!!!") == 0) {
		return '#'; 
	}else {
		return '%'; 
	}
	}


