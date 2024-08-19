function solution(word) {
    var answer = 0;
    let cnt = -1;
    
    let vowel = "AEIOU";
    
    function DFS(tmp){
        cnt++;
        
        if(tmp === word){
            answer = cnt;
            return;
        }
        if(tmp.length >= 5)
            return;
        
        for(let i=0; i<vowel.length; i++)
            DFS(tmp+vowel[i]);
    }
    
    DFS("");
    
    return answer;
}