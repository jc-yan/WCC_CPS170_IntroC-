//Author: Jiachen Yan
//Date: 2020-06-14
//Instructor: Prof. David Rodgers
//Project name: College Acceptance System

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream read("mp2accept.txt"); //load the file

    ofstream write("Output.txt"); // define a output file steam

    string applicant; //define an object to store each applicant's info

    //set up variables of applicants' info
    string school, alumnus;
    double gpa;
    int math, verbal;

    //set up counters for applicants
    int liberal_arts_accepted = 0;
    int music_accepted = 0;
    int total_applicants = 0;

    cout << "Acceptance to College by Jiachen Yan\n" << endl;
    write << "Acceptance to College by Jiachen Yan\n" << endl; //write out

    int i = 0;
    while(!read.eof()){ //the loop will end until it hits the final line of the input file
        i++; 
        total_applicants++; //increment the total applicants by 1
        bool accept = true;
        string rejection = "Rejected -";
        getline(read, applicant); //get a line in the input file, store it in the applicant variable

        // parse each line, store in the variables
        school = applicant.front();
        gpa = strtof((applicant.substr(2, 3)).c_str(), 0);
        math = stoi(applicant.substr(6, 3));
        verbal = stoi(applicant.substr(10, 3));
        alumnus = applicant.back();

        // print out applicant info
        cout << "Applicant #: " << i << endl;
        cout << "School = " << school << " GPA = " << gpa << " math = " << math;
        cout << " verbal = " << verbal << " alumnus = " << alumnus << endl;

        //write to the output file
        write << "Applicant #: " << i << endl;
        write << "School = " << school << " GPA = " << gpa << " math = " << math;
        write << " verbal = " << verbal << " alumnus = " << alumnus << endl;

        //use if-else to finish the acceptance process
        if (school == "L") { //1. liberal arts school students
            cout << "Applying to " << "Liberal Arts" << endl;
            write << "Applying to " << "Liberal Arts" << endl;//write

            if (liberal_arts_accepted >= 5) {
                cout << "Rejected! Already max number of liberal arts students accepted!" << endl;
                cout << "******************************" << endl;

                //write
                write << "Rejected! Already max number of liberal arts students accepted!" << endl;
                write << "******************************" << endl;
                
                continue;
            }

            if (alumnus == "Y") {
                if (gpa < 3.0) {
                accept = false;
                rejection += " GPA is too low.";
                 }

            if ((math + verbal) < 1000) {
                accept = false;
                rejection +=  " SAT is too low.";
                }
            }  

        else {
            if (gpa < 3.5) {
                accept = false;
                rejection += " GPA is too low.";
            }

            if ((math + verbal) < 1200) {
                accept = false;
                rejection += " SAT is too low.";
            }
        }

        if (accept) {
            liberal_arts_accepted++;
            cout << "Accepted to Liberal Arts!!!" << endl << "******************************" << endl;

            write << "Accepted to Liberal Arts!!!" << endl << "******************************" << endl;
        } else {
            cout << rejection << endl << "******************************" << endl;
            write << rejection << endl << "******************************" << endl;
        }
          continue;

        } 
        
        //2. music school students
        else {
            cout << "Applying to " << "Music" << endl;
            write << "Applying to " << "Music" << endl;

            if (music_accepted >= 3) {
                cout << "Rejected! Already max number of music students accepted!" << endl;
                cout << "******************************" << endl;

                write << "Rejected! Already max number of music students accepted!" << endl;
                write << "******************************" << endl;
                continue;
            }

            if (math < 500){
                accept = false;
                rejection += " SAT math score is too low.";
            }

            if (verbal < 500) {
                accept = false;
                rejection += " SAT verbal score is too low.";
            }

        if (accept) {
            music_accepted++;
            cout << "Accepted to Music!!!" << endl << "******************************" << endl;
            write << "Accepted to Music!!!" << endl << "******************************" << endl;
        } else {
            cout << rejection << endl << "******************************" << endl;
            write << rejection << endl << "******************************" << endl;
        }
    }
  }
    // print out the summary
    cout << "\nThere were " << total_applicants << " applicants in the file." << endl;
    cout << "There were " << liberal_arts_accepted << " acceptances to Liberal Arts." << endl;
    cout << "There were " << music_accepted << " acceptances to Music." << endl;

    //write out
    write << "\nThere were " << total_applicants << " applicants in the file." << endl;
    write << "There were " << liberal_arts_accepted << " acceptances to Liberal Arts." << endl;
    write << "There were " << music_accepted << " acceptances to Music." << endl;
    
    
    //close the files
    read.close();
    write.close();

    //end the program
    cout << "Press any key to continue\n";
    cin.ignore();
    cin.get();
}
