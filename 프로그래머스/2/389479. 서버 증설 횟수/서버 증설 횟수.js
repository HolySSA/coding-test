function solution(players, m, k) {
    let answer = 0, cur = Array(players.length).fill(0);

    for (let i = 0; i < players.length; i++) {
        let active = 1 + cur[i];
        let need = Math.floor(players[i] / m) + 1;

        if (need > active) {
            let extra = need - active;
            for (let j = 0; j < k; j++) {
                cur[i + j] += extra;
            }

            answer += extra;
        }
    }

    return answer;
}