function solution(fees, records) {
    let answer = [];
    
    let cars = {};
    records.forEach(record => {
        let [time, car, inout] = record.split(" ");
        
        let [hour, minute] = time.split(":");
        time = Number(hour * 60) + Number(minute);
        
        if (!cars[car])
            cars[car] = { time: 0, car };
        
        cars[car].inout = inout;
        
        if (inout === "OUT") {
            cars[car].time += time - cars[car].lastInTime;
            return;
        }
        
        cars[car].lastInTime = time;
    });
    
    Object.values(cars).sort((a, b) => a.car - b.car).map(c => {
        if (c.inout === "IN")
            c.time += (23*60 + 59) - c.lastInTime;

        if (fees[0] > c.time){
            answer.push(fees[1]);
            return;
        }
        
        answer.push(fees[1] + Math.ceil((c.time - fees[0]) / fees[2]) * fees[3]);
    });
    
    return answer;
}