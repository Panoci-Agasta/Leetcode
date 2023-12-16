#include<iostream>
#include<map>

using namespace std;

bool isAnagram(string,string);

int main(){
    string str1 = "hello";
    string str2 = "elloh";

    bool myans;
    myans = isAnagram(str1,str2);
    cout << myans << "\n";

    return 0;
}

bool isAnagram(string s, string t) {
    map<char,int> hashmap;
    int size1 = s.length();
    int size2 = t.length();
    if(size1 != size2){
        return false;
    }
    else{
        for(int i = 0;i < size1;i++){
            if(hashmap.find(s[i]) != hashmap.end()){
                hashmap[s[i]] += 1;
            }else{
                hashmap.insert(pair<char,int>(s[i],1));
            }
        }
        for(int i = 0;i < size1;i++){
            if(hashmap.find(t[i]) != hashmap.end()){
                hashmap[t[i]] -= 1;
            }
        }
    }
    for(const auto& elem : hashmap)
    {
        if(elem.second != 0){
            return false;
        }
    }

    return true;
}
