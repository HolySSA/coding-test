function solution(N, road, K) {
    const infos = Array.from({ length: N + 1 }, () => []);
    const accum = Array(N + 1).fill(2e9);

    road.forEach((info) => {
        let [a, b, c] = info;
        
        infos[a].push({ to: b, time: c }); 
        infos[b].push({ to: a, time: c }); 
    });

    const pq = [{ to: 1, time: 0 }];
    accum[1] = 0;

    while(pq.length !== 0) {
        let {to, time} = pq.pop();

        infos[to].forEach(next => {
            if(accum[next.to] > accum[to] + next.time) {
                accum[next.to] = accum[to] + next.time;
                pq.push(next);
            }
        })
    }

    return accum.filter((item) => {
        return item <= K
    }).length;
}