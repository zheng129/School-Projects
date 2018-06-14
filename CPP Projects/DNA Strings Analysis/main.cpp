//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 1

// Analyzing DNA strings information and generate more DNA strings that match the previous analysis

// The generating strings part is unfinished. I could not find a proper way to generate
// strings that the length is determined by variance and standard deviation and also follow
// the relative frequency calculated previously.

// I think I have the right numbers of variance, standard deviation, and relative frequency.
// However, the last step of actually generating the strings really got me stuck.

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <ctype.h>

using namespace std;

void read_file(string name);
void write_file(string s);
void my_info();
void generateStrings(float possOfA, float possOfT, float possOfG, float possOfC,
                     float possOfAA, float possOfAT, float possOfAG, float possOfAC,
                     float possOfTA, float possOfTT, float possOfTG, float possOfTC,
                     float possOfCA, float possOfCT, float possOfCG, float possOfCC,
                     float possOfGA, float possOfGT, float possOfGG, float possOfGC);

float lengthOfLine = 0;
float sum = 0;
float numOfLines = 0;
float mean = 0;
float temp = 0;
float variance = 0;
float stdDev = 0;
float num1 = 0;
float num2 = 0;
float num1Log = 0;
float num2Cos = 0;
float C = 0;
float D = 0;

/* The main method
 * It returns an int
 * It takes an int and an array of command
 */

int main(int argc, char** argv) {
    
    string name = "";
    string choice = "";
    
    
    cout << "\nEnter the name of the file: " << endl;
    cin >> name;
    
    my_info();
    write_file("The name of the file is: " + name);
    read_file(name);
    
    cout << "\nDo you want to analyze another file? (type yes to process, or anything else to exit) " << endl;
    cin >> choice;
    
    if (choice == "yes"){
        cout << "\nEnter the name of the second file: " << endl;
        cin >> name;
        
        write_file("The name of the file is: " + name);
        read_file(name);
    }
    else{
        exit(0);
    }
    
    return 0;
}

/* The method supposed to generate srtings with certain length,
 * and distributes similarly as the previous analysis
 * It returns nothing
 * It takes many float numbers as the data to calculate the distributions of letters
 * and combination of letters
 */

void generateStrings(float possOfA, float possOfT, float possOfG, float possOfC,
                     float possOfAA, float possOfAT, float possOfAG, float possOfAC,
                     float possOfTA, float possOfTT, float possOfTG, float possOfTC,
                     float possOfCA, float possOfCT, float possOfCG, float possOfCC,
                     float possOfGA, float possOfGT, float possOfGG, float possOfGC){
    
    float num1 = ((double) rand() / (RAND_MAX));
    float num2 = ((double) rand() / (RAND_MAX));
    float num1Log = log(num1);
    float num2Cos = cos(2 * num2 * M_PI);
    float C = pow( ( ( (-2) * num1Log ) * num2Cos), 1/2 );
    float D = (C * stdDev) + mean;
    int lenOfLine = ceil(D);
        
    string generatedStr;
    
    /*
     * Cannot figure out what to do here
     */
    
}

/* The method writes my personal information into the output file
 * It returns nothing
 * It takes no paramaters
 */

void my_info(){
    string info = "Yixing Zheng\n2293298\nzheng129@mail.chapman.edu\nCPSC 350\nProject 1\n";
    write_file(info);
}

/* The methods write information into the output file
 * It returns nothing
 * It takes a string as input
 */

void write_file(string s){
    ofstream out;
    out.open("Yixing Zheng.txt",ios::app);
    
    
    if (out.is_open())
    {
        out << s << endl;
        out.close();
    }
    else cout << "Unable to open file";
}

/* The method reads the input file and calculates the numbers needed for analysis
 * It also calls the write_file() and generateStrings() methods to start the process of outputting information
 * It returns nothing
 * It takes a string of the name of the input file
 */

void read_file(string name){
    
    string line;
    char nucleotide;
    char tempNuc;
    string null = "";
    
    float countLetters = 0;
    float countA = 0;
    float countT = 0;
    float countG = 0;
    float countC = 0;
    
    float countAA = 0;
    float countAT = 0;
    float countAC = 0;
    float countAG = 0;
    
    float countTA = 0;
    float countTT = 0;
    float countTC = 0;
    float countTG = 0;
    
    float countCA = 0;
    float countCT = 0;
    float countCC = 0;
    float countCG = 0;
    
    float countGA = 0;
    float countGT = 0;
    float countGC = 0;
    float countGG = 0;
    
    ifstream myfile(name);
    
    sum = 0;
    numOfLines = 0;
    
    while (getline(myfile, line)){
        
        lengthOfLine = line.length();
        sum += lengthOfLine;
        numOfLines++;
        mean = sum / numOfLines;
    }
    
    myfile.close();
    myfile.open(name);
    
    temp = 0;
    
    while (getline(myfile, line)){
        
        lengthOfLine = line.length();
        temp += (lengthOfLine - mean) * (lengthOfLine - mean);
        variance = temp / (numOfLines);
        stdDev = pow(variance, 0.5);
        
        for(int i = 0; i < line.length();++i){
            
            nucleotide = line[i];
            toupper(nucleotide);
            tempNuc = line[i+1];
            toupper(tempNuc);
            
            if (nucleotide == 'A'){
                countA++;
                countLetters++;
                
                if(tempNuc == 'A'){
                    countAA++;
                }
                else if(tempNuc == 'T'){
                    countAT++;
                }
                else if(tempNuc == 'C'){
                    countAC++;
                }
                else if(tempNuc == 'G'){
                    countAG++;
                }
                
            }
            else if (nucleotide == 'T'){
                countT++;
                countLetters++;
                
                if(tempNuc == 'A'){
                    countTA++;
                }
                else if(tempNuc == 'T'){
                    countTT++;
                }
                else if(tempNuc == 'C'){
                    countTC++;
                }
                else if(tempNuc == 'G'){
                    countTG++;
                }
                
            }
            else if (nucleotide == 'C'){
                countC++;
                countLetters++;
                
                if(tempNuc == 'A'){
                    countCA++;
                }
                else if(tempNuc == 'T'){
                    countCT++;
                }
                else if(tempNuc == 'C'){
                    countCC++;
                }
                else if(tempNuc == 'G'){
                    countCG++;
                }
                
            }
            else if(nucleotide == 'G'){
                countT++;
                countLetters++;
                
                if(tempNuc == 'A'){
                    countGA++;
                }
                else if(tempNuc == 'T'){
                    countGT++;
                }
                else if(tempNuc == 'C'){
                    countGC++;
                }
                else if(tempNuc == 'G'){
                    countGG++;
                }
                
            }
        }
    }
    myfile.close();
    
    string sumPrint = "The sum of all lines is " + to_string(sum);
    string meanPrint = "The mean of all lines is " + to_string(mean);
    string varPrint = "The variance of all length is: " + to_string(variance);
    string stdDevPrint = "The standard deviation of all length is: " + to_string(stdDev);
    
    float possOfA = countA / countLetters;
    float possOfT = countT / countLetters;
    float possOfG = countG / countLetters;
    float possOfC = countC / countLetters;
    
    
    float possOfAA = countAA / countLetters;
    float possOfAT = countAT / countLetters;
    float possOfAG = countAG / countLetters;
    float possOfAC = countAC / countLetters;
    
    float possOfTA = countTA / countLetters;
    float possOfTT = countTT / countLetters;
    float possOfTG = countTG / countLetters;
    float possOfTC = countTC / countLetters;
    
    float possOfCA = countCA / countLetters;
    float possOfCT = countCT / countLetters;
    float possOfCG = countCG / countLetters;
    float possOfCC = countCC / countLetters;
    
    float possOfGA = countGA / countLetters;
    float possOfGT = countGT / countLetters;
    float possOfGG = countGG / countLetters;
    float possOfGC = countGC / countLetters;
    
    string rPOfA = "The relative possibility of A is: " + to_string(possOfA * 100) + "%";
    string rPOfT = "The relative possibility of T is: " + to_string(possOfT * 100) + "%";
    string rPOfG = "The relative possibility of G is: " + to_string(possOfG * 100) + "%";
    string rPOfC = "The relative possibility of C is: " + to_string(possOfC * 100) + "%";
    
    string rPOfAA = "The relative possibility of AA is: " + to_string(possOfAA * 100) + "%";
    string rPOfAT = "The relative possibility of AT is: " + to_string(possOfAT * 100) + "%";
    string rPOfAG = "The relative possibility of AG is: " + to_string(possOfAG * 100) + "%";
    string rPOfAC = "The relative possibility of AC is: " + to_string(possOfAC * 100) + "%";
    
    string rPOfTA = "The relative possibility of TA is: " + to_string(possOfTA * 100) + "%";
    string rPOfTT = "The relative possibility of TT is: " + to_string(possOfTT * 100) + "%";
    string rPOfTG = "The relative possibility of TG is: " + to_string(possOfTG * 100) + "%";
    string rPOfTC = "The relative possibility of TC is: " + to_string(possOfTC * 100) + "%";
    
    string rPOfCA = "The relative possibility of CA is: " + to_string(possOfCA * 100) + "%";
    string rPOfCT = "The relative possibility of CT is: " + to_string(possOfCT * 100) + "%";
    string rPOfCG = "The relative possibility of CG is: " + to_string(possOfCG * 100) + "%";
    string rPOfCC = "The relative possibility of CC is: " + to_string(possOfCC * 100) + "%";
    
    string rPOfGA = "The relative possibility of GA is: " + to_string(possOfGA * 100) + "%";
    string rPOfGT = "The relative possibility of GT is: " + to_string(possOfGT * 100) + "%";
    string rPOfGG = "The relative possibility of GG is: " + to_string(possOfGG * 100) + "%";
    string rPOfGC = "The relative possibility of GC is: " + to_string(possOfGC * 100) + "%";
    
    write_file(sumPrint);
    write_file(meanPrint);
    write_file(varPrint);
    write_file(stdDevPrint);
    write_file(null);
    
    write_file(rPOfA);
    write_file(rPOfT);
    write_file(rPOfG);
    write_file(rPOfC);
    write_file(null);
    
    write_file(rPOfAA);
    write_file(rPOfAT);
    write_file(rPOfAG);
    write_file(rPOfAC);
    write_file(null);
    
    write_file(rPOfTA);
    write_file(rPOfTT);
    write_file(rPOfTG);
    write_file(rPOfTC);
    write_file(null);
    
    write_file(rPOfCA);
    write_file(rPOfCT);
    write_file(rPOfCG);
    write_file(rPOfCC);
    write_file(null);
    
    write_file(rPOfGA);
    write_file(rPOfGT);
    write_file(rPOfGG);
    write_file(rPOfGC);
    write_file(null);
    
    generateStrings(possOfA, possOfT, possOfG, possOfC,
                    possOfAA, possOfAT, possOfAG, possOfAC,
                    possOfTA, possOfTT, possOfTG, possOfTC,
                    possOfCA, possOfCT, possOfCG, possOfCC,
                    possOfGA, possOfGT, possOfGG, possOfGC);
    
}

