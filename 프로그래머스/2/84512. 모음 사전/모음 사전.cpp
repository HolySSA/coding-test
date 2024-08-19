#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = -1;
int answer = 0;
string vowel = "AEIOU";

void DFS(string word, string target){
    cnt++;
    
    if(word == target){
        answer = cnt;
        return;
    }
    
    if(word.length() >= 5)
        return;
    
    for(int i=0; i<vowel.length(); i++)
        DFS(word+vowel[i], target);
}

int solution(string word) {
    DFS("", word);
    
    return answer;
}