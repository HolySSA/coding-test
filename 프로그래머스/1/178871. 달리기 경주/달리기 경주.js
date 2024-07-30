function solution(players, callings) {
    let rank = {};
    
    for(let i=0; i<players.length; i++)
        rank[players[i]] = i;

    callings.forEach((name) => {
        let cur_rank = rank[name];

        rank[players[cur_rank]]--;
        rank[players[cur_rank-1]]++;
        
        // swap
        [players[cur_rank], players[cur_rank-1]] = [players[cur_rank-1], players[cur_rank]];
    });
    
    return players;
}