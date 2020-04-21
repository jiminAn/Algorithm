#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int Palindrome(string s);
int solution(string s)
{
    int answer;
    answer = Palindrome(s);
    return answer;
}
int Palindrome(string s){
    int check;
    int j,k;
    vector<int> v;
    if(s.length() == 1)
        return 1;
    if(s.length() == 2){
        if(s[0] == s[1])
            return 2;
        else
            return 1;
    }
    for(int i = 1; i < s.length(); i++){ //홀수 palindrome 검사
            check = 1;
            for(j = 1, k = 1; (i-j) >= 0 && (i+k) < s.length();j++,k++){
                if(s[i-j] == s[i+k])
                    check += 2;
                else 
                    break;
            }
            if(check != 1)
                v.push_back(check);
            if(check == s.length() || check == s.length()-1)
                break;
    }
    for(int i = 1; i < s.length(); i++){ //짝수 palindrome 검사
            check = 1;
            if(s[i] == s[i+1]){
                check++;
                for(j = 1, k = 2; (i-j) >= 0 && (i+k) < s.length();j++,k++){
                    if(s[i-j] == s[i+k])
                        check += 2;
                    else 
                        break;
                }
                if(check != 1)
                    v.push_back(check);
                if(check == s.length() || check == s.length()-1)
                    break;
            }
    }
    return *max_element(v.begin(), v.end());
}
