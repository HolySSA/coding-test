function strToMinute(str) {
    let [a, b] = str.split(":");
    
    return parseInt(a) * 60 + parseInt(b);
}

function solution(book_time) {
    book_time.sort();
    
    let time = [];
    time.push(strToMinute(book_time[0][1]) + 10);
    
    book_time.forEach((t, i) => {
        if(i === 0)
            return;
        
        const startTime = strToMinute(t[0]);
        const idx = time.findIndex((endTime) => endTime <= startTime);
        
        if (idx === -1)
            time.push(strToMinute(t[1]) + 10);
        else
            time[idx] = strToMinute(t[1]) + 10;
    });
    
    return time.length;
}