function solution(id_list, report, k) {
    var answer = [];
    
    // id_list 크기만큼 0 삽입
    id_list.forEach(()=>{
        answer.push(0);
    });
    
    // id_list 크기만큼 report_list에 신고받은 사람, 배열 삽입
    let report_list = {};
    id_list.map((s)=>{
    	return report_list[s] = [];
    });
    // 
    report.map((user)=>{
        // 0 신고한 사람, 1 신고받은 사람
    	let arr = user.split(" ");
		if(!report_list[arr[1]].includes(arr[0]))
        	report_list[arr[1]].push(arr[0]);
    });
    
    for(let list in report_list){
        // 신고한 사람이 k보다 많으면
    	if(report_list[list].length >= k){
        	report_list[list].map((arr)=>{
            	answer[id_list.indexOf(arr)]++;
            });
        }
    }
    
    return answer;
}