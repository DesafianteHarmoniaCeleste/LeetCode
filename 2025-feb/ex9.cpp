#include <iostream>


using namespace std;

bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    else{
        int reversed=0;
        int original=x;

        while(x!=0){

            reversed= (reversed*10) + (x%10);
            x/=10;
        }

        return reversed==original;
    }
}

int main(){
    int value;
    cin>>value;
    if(isPalindrome(value)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
