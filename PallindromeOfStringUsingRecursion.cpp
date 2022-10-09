
#include <iostream>

using namespace std;

bool isPallindrome(string s,int i,int j){
    if(i>=j){
        return true;
    }
    if(s[i]!=s[j]){
        return false;
    }

    return (s,i+1,j-1);
}

int main()
{
 if(isPallindrome("vikrant",0,2)){
     cout<<"Pallidrome";
 }

    else{
        cout<<"Not Pallidrome";
    }

return 0;
}
