function solution(users, emoticons) {
    let answer = [];
    
    let emoPlus = 0;
    let emoPrice = 0;
    
    let sales = [ 10, 20, 30, 40 ];
    let applies = [];
    
    function saleApply() {
        if(applies.length === emoticons.length) {
            let curPlus = 0;
            let curPrice = 0;
            
            for(let i = 0; i < users.length; i++) {
                let sum = 0;
                
                for(let j = 0; j < emoticons.length; j++) {
                    if(users[i][0] <= applies[j]) {
                        let sale = emoticons[j] * (100 - applies[j]) / 100;
                        sum += sale;
                    }
                }
                
                if(sum >= users[i][1])
                    curPlus++;
                else
                    curPrice += sum;
            }
            
            if(emoPlus < curPlus) {
                emoPlus = curPlus;
                emoPrice = curPrice;
            }
            else if(emoPlus === curPlus && emoPrice < curPrice) {
                emoPrice = curPrice;
            }

            return;
        }

        for(let i = 0; i < sales.length; i++) {
            applies.push(sales[i]);
            saleApply();
            applies.pop();
        }
    }
    
    saleApply();
    
    answer.push(emoPlus);
    answer.push(emoPrice);
    
    return answer;
}