#include<iostream>
#include<string>
using namespace std;

int main(){
    
}
class Solution {
public:
    // possible optimization = pass the size of the password as a parameter. 
    bool checkSize(string password,int size){
        if (size < 8 ){
            return false;
        }else{
            return true;
        }
    }
    bool checkLowercase(string password,int size){
        // for(int i = 0;i < size;i++){
        //     if(password[i].islower()){
        //         return true;
        //     }
        // }
        // return false;
    }
    bool strongPasswordCheckerII(string password) {
        int passSize = password.size();

    }
};