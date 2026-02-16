// Bartosz Marcińczyk
// Program calculates Levenshtein distance and similarity
// for two words or sentences provided by user or file

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <algorithm>



// Validation of strings (strings can't be empty)
bool validate_input(const std::string& s){
    return s.find_first_not_of(" \t\n\r") != std::string::npos;
}

// Validation of file and strings in file
bool validate_from_file(const std::string& filename, std::string& s1, std::string& s2){
    std::ifstream file(filename);
    if (!file) return false;

    if (!std::getline(file,s1)) return false;
    if (!std::getline(file,s2)) return false;

    return validate_input(s1) && validate_input(s2);
}

// Function to read cand1 and cand2 from keyboard with validation
void inputFromKeyboard(std::string& s1, std::string& s2){

    std::cout<<"Enter first word/sentence: ";
    std::getline(std::cin,s1);

    // Check is input correct
    while(!validate_input(s1)){
        std::cout<<"Invalid input!\n";
        std::cout<<"Enter correct first word/sentence: ";
        std::getline(std::cin,s1);
    }
    
    std::cout<<"Enter second word/sentence: ";
    std::getline(std::cin,s2);

    // Check is input correct
    while(!validate_input(s2)){
        std::cout<<"Invalid input!\n";
        std::cout<<"Enter correct second word/sentence: ";
        std::getline(std::cin,s2);
    }
    std::cout<<"Input loaded successfully.\n\n";
    
}

// Function to read cand1 and cand2 from file with validation
void inputFromFile(std::string& s1, std::string& s2){
    std::string filename;

    while (true){
        std::cout<<"Enter file name: ";
        std::cin>>filename;

        if(validate_from_file(filename,s1,s2))
        {
            break;
        }
        std::cout<<"Invalid file or invalid content!\n";
    }
    std::cout<<"Input loaded successfully.\n\n";
}


// Levenshtein algorithm

int Levenshtein(const std::string& a, const std::string& b){
    // Take shorter string to calculate for save memory
    const std::string& s = (a.size()<=b.size()) ? a:b;
    const std::string& t = (a.size()<=b.size()) ? b:a;

    const size_t n=s.size();
    const size_t m=t.size();

    std::vector<int> prev(m+1), curr(m+1);

    // Cost of insertions
    for (size_t j=0;j<=m;j++)
        prev[j]=j;

    for (size_t i=1;i<=n;i++){
        curr[0]=i; // Cost of removals

        for (size_t j=1;j<=m;j++){
            int cost = (s[i-1]==t[j-1]) ? 0:1;

            curr[j]=std::min({
                prev[j]+1, //delete
                curr[j-1]+1, // insert
                prev[j-1]+cost // substitute
            });
        }
        std::swap(prev,curr);
    }

    return prev[m];
}

// Function for calculate percent of similarity

double Similarity(const std::string& a, const std::string& b){
    int dist=Levenshtein(a,b);
    size_t max_len=std::max(a.size(),b.size());

    if(max_len==0) return 1.0;
    return 1.0-static_cast<double>(dist) / max_len;
}



int main(){

    std::string cand1;
    std::string cand2;
    int option=0;

    std::cout<<"Hello in program to calculate similarity of two words/sentences with algorithm of Levenshtein\n";
    std::cout<<"You can choose in which form you want send two words/sentences to compare(type 1 or 2):\n 1. Type words/sentences by keyboard \n 2. Read words/sentences from file\n";

    // Check is input of option is proper
    while (true){
        std::cout<<"Type your choice: ";
        
        if (std::cin>>option && (option==1 || option==2)){
            break;
        }
        else{
            std::cout<<"Invalid input. Input must be 1 or 2\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Execution options
    if(option==1){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputFromKeyboard(cand1,cand2);
    }else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputFromFile(cand1,cand2);
    }

    // Show result of calculation
    int distance=Levenshtein(cand1,cand2);
    std::cout<<"Levenshtein distance: "<<distance<<"\n";
    std::cout<<"Levenshtein similarity in precent: "<<Similarity(cand1,cand2)*100<<"%\n";

    return 0;
}



