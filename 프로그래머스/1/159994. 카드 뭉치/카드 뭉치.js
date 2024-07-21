function solution(cards1, cards2, goal) {
    let cards1_idx = 0;
    let cards2_idx = 0;
    
    while(cards1_idx+cards2_idx < goal.length){
        if(cards1_idx<cards1.length && cards1[cards1_idx] == goal[cards1_idx+cards2_idx])
            cards1_idx++;
        else if(cards2_idx<cards2.length && cards2[cards2_idx] == goal[cards1_idx+cards2_idx])
            cards2_idx++;
        else
            return "No";
    }
    
    return "Yes";
}