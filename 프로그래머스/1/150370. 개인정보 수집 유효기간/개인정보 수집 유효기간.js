function solution(today, terms, privacies) {
    var answer = [];
    
    let today_info = today.split('.'); // 1 : 연, 2 : 월, 3 : 일
    let today_num = [];
    today_info.forEach((a) => {
        today_num.push(parseInt(a));
    });
    
    for(let i=0; i<privacies.length; i++){
        let date = privacies[i].split(' '); // 0 : 날짜, 2 : 문자
        
        terms.forEach((s) => {
            let limit = s.split(' '); // 0 : 문자, 1 : 개월
            
            if(date[1] === limit[0]){
                let date_info = date[0].split('.');
                let date_num = [];
                date_info.forEach((a) => {
                    date_num.push(parseInt(a));
                });
                date_num[1] += parseInt(limit[1]);
                
                while(date_num[1] > 12){
                    date_num[1] -= 12;
                    date_num[0] += 1;
                }
                
                if(today_num[0] > date_num[0])
                    answer.push(i+1);
                else if(today_num[0] < date_num[0]){
                    
                }
                else{
                    if(today_num[1] > date_num[1])
                        answer.push(i+1);
                    else if(today_num[1] < date_num[1]){
                        
                    }
                    else{
                        if(today_num[2] >= date_num[2])
                            answer.push(i+1);
                        else{
                            
                        }
                    }
                }
            }
        });
    }
    
    
    return answer;
}