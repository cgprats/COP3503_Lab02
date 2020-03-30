#include <iostream>
#include <string>
#include <vector>
//FIXME: stream manipulation library
#include <iomanip>
using namespace std;

int main()
{
   string title,headerOne,headerTwo,input,afterComma;
   int commaCount = 0;
   int commaLocation = 0;
   bool validInput = 0;
   bool followedByInt = 1;
   string dataString;
   int dataInt;
   int asterisks;
   vector<string> stringComp;
   vector<int> intComp;
   /* Type code here. */
   /* Overall flow of the program:
   Get some input for the title*/
   cout << "Enter a title for the data:" << endl;;
   getline(cin, title);
   cout << "You entered: " << title << endl;
   /*Get some input for column header #1
   Get some input for column header #2*/
   cout << "\nEnter the column 1 header:" << endl;
   getline(cin, headerOne);
   cout << "You entered: " << headerOne << endl;
   cout << "\nEnter the column 2 header:" << endl;
   getline(cin, headerTwo);
   cout << "You entered: " << headerTwo << endl;
   /*Until the user types "-1":*/
   while (input != "-1") {
   /*Get input for a string*/
	   cout << "\nEnter a data point (-1 to stop input):" << endl;
	   getline(cin, input);
   /*Validate input*/
	   if (input != "-1") {
	   commaCount = 0;
	   for (unsigned int i = 0; i < input.size(); i++) {
		   if (input.at(i) == ',') {
			   commaCount++;
			   commaLocation = i;
		   }
	   }
	   afterComma = input.substr(commaLocation + 1, input.size() - 1);
	   if (commaCount != 0) {
		   try {
			   dataInt = stoi(afterComma);
			   followedByInt = 1;
		   }
		   catch(invalid_argument& excpt) {
			   followedByInt = 0;
	   	}
	   }
	   if (commaCount == 1 && followedByInt) {
		   validInput = 1;
	   }
	   else {
		   validInput = 0;
	   }
	   if (!validInput) {
		   if (commaCount == 0) {
			   cout << "Error: No comma in string." << endl;
		   }
		   else if (commaCount > 1) {
			   cout << "Error: Too many commas in input." << endl;
		   }
		   else if (!followedByInt) {
			   cout << "Error: Comma not followed by an integer." << endl;
		   }
	   }
   /*If valid...*/
	   else if (validInput) {
      /*Split
      Validate second half of input
      If also valid...
         Store separate pieces*/
	   	dataString = input.substr(0, commaLocation);
	   	cout << "Data string: " << dataString << endl;
		stringComp.push_back (dataString);
	   	cout << "Data integer: " << dataInt << endl;
		intComp.push_back (dataInt);
	   }
	   }
   }
   
   /*Print out data in table format*/
   cout << endl;
   cout << setw(33) << right << title << endl;
   cout << setw(20) << left << headerOne << "|" << setw(23) << right << headerTwo << endl;
   cout << "--------------------------------------------" << endl;
   for (unsigned int i = 0; i < stringComp.size(); i++) {
	   cout << setw(20) << left << stringComp[i] << "|" << setw(23) << right << intComp[i] << endl;
   }
   /*Print out data in chart format
   */
   cout << endl;
   for (unsigned int i = 0; i < stringComp.size(); i++) {
	   cout << setw(20) << right << stringComp[i] << " ";
	   asterisks = 0;
	   while (asterisks < intComp[i]) {
		   cout << "*";
		   asterisks++;
	   }
	   cout << endl;
   }
   
   return 0;
}
