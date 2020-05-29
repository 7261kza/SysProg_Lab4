#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int amountOfHoney=1;
bool alive = true;
bool hungry = false;

int main()
{   
    char buff[50];
    char buff2[50];
    int stealHoney=30;
    
    pid_t temp;
    temp = fork();
    if (temp == 0){
    while (amountOfHoney > 0)
    {		
	cout << endl;
        ifstream fin("file.txt");  // open file
        fin >> buff; // read all information from file into buffer
        fin.close(); //close file
        amountOfHoney=atoi(buff);
/*        
        if ((amountOfHoney < 0) && (hungry == true)) 
        {
        	cout << "Медведь скончался!" << endl;
        	alive = false;
        } else    if (amountOfHoney <= 0) 
        {
        	cout << "Медведь голоден!" << endl;
        	hungry = true;
        } else 
        {
 */          
        amountOfHoney -= stealHoney;
        cout << "PID медведя\t" << getpid() << endl;
        cout << "МЕДВЕДЬ съел мед:\t" << amountOfHoney << endl;
        
        sprintf(buff, "%d", amountOfHoney);  // put honey from number into string (our buffer)
        ofstream fout("file.txt");  // created an object and open file
        fout << buff; // write buffer into file
        fout.close(); // closed file
        cout << endl;

        sleep(7);
        
    }
    
    } else if (temp > 0)
	{
    
    		pid_t  proc_child; 

		do{

            
        		proc_child = fork();

        		wait(0);

        		switch (proc_child)

        		{

        			case 0:

            			cout << "PID пчелы\t" << getpid() << endl;
            			execl("bee", " " ,  NULL);
            			kill(getpid(), SIGKILL);
            			break;
        		}

        	cout << endl << endl;
        	ifstream fin3("file.txt");  // open file
        	fin3 >> buff2; // read all information from file into buffer
        	fin3.close(); //close file

        	amountOfHoney=atoi(buff2);
    	
    		//if (amountOfHoney <= 0) {alive = false;}
    		} while (amountOfHoney > 0);
	}
return 0;
}   
