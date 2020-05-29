#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[])
{
	int amountHoney; 
	int honeyOfBee = 5;
	
	srand(time(NULL)); 
	
	char buffer[50]; // created a buffer for writting into file
	
    	ifstream fin("file.txt");
    	fin >> buffer;
    	fin.close();
    	amountHoney=atoi(buffer);
    	
    	amountHoney += honeyOfBee;
    	cout << "ПЧЕЛА принесла мед:\t"<< amountHoney<<endl;
	sprintf(buffer, "%d", amountHoney);  // put honey from number into string (our buffer)
	ofstream fout("file.txt");  // created an object and open file
  	fout << buffer; // write buffer into file
    	fout.close(); // closed file
    	sleep(2);	
} 
