function solution(elements) {
    let nums = new Set();
    for(let i=0; i<elements.length; i++){
        let sum=0;
        for(let j=i; j<i+elements.length; j++){
            let tmp = j % elements.length;
            sum += elements[tmp];
            nums.add(sum);
        }
    }
    
    return nums.size;
}