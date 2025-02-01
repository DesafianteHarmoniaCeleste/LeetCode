#include <iostream>
#include <string>
#define possible_char 95 
#define initial_char 32
using namespace std;


int lengthOfLongestSubstring(string s){
    int vector[possible_char]= {0};
    int return_value= 0;
    int start= 0;
    int count= 0;

    for (int i= 0; i< s.size(); i++) {
        char c= s[i];
        int pos= static_cast<int>(c)- initial_char;

        if(vector[pos]> start){ start= vector[pos]; }

        vector[pos]= i+ 1;
        count= i - start + 1;

        if(count> return_value){
            return_value= count;
        }
    }

    return return_value;
}

int main(){
    string input;
    getline(cin, input);
    cout<< lengthOfLongestSubstring(input);
    return 0;
}