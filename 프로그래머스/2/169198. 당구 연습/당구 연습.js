function solution(m, n, startX, startY, balls) {
    let answer = [];
    let distanceX, distanceY, check;
    
    for(const ball of balls) {
        let distance = Infinity;
        
        let distanceX = (startX - ball[0]) ** 2;
        let distanceY = (startY - ball[1]) ** 2;
        
        // (원쿠션 거리)^2: (두 공 사이의 거리)^2 + (두 공의 쿠션할 벽까지의 거리합)^2 
        
        if(startX !== ball[0]) {
            check = distanceX + (startY + ball[1]) ** 2; // 아래 쿠션
            distance = Math.min(distance, check);
            
            check = distanceX + ((n - startY) + (n - ball[1])) ** 2; // 위 쿠션
            distance = Math.min(distance, check);
        } else {
            // X 좌표가 같으면 쿠션하다가 부딪치기 때문에 따로 관리
            if(startY < ball[1]) {
                check = distanceX + (startY + ball[1]) ** 2; // 아래 쿠션
                distance = Math.min(distance, check);
            } else {
                check = distanceX + ((n - startY) + (n - ball[1])) ** 2; // 위 쿠션
                distance = Math.min(distance, check);
            }
        }
        
        if(startY !== ball[1]) {
            check = distanceY + (startX + ball[0]) ** 2; // 왼 쿠션
            distance = Math.min(distance, check);
            
            check = distanceY + ((m - startX) + (m - ball[0])) ** 2; // 오른 쿠션
            distance = Math.min(distance, check);
        } else {
            // Y 좌표가 같으면 쿠션하다가 부딪치기 때문에 따로 관리
            if(startX < ball[0]) {
                check = distanceY + (startX + ball[0]) ** 2; // 왼 쿠션
                distance = Math.min(distance, check);
            } else {
                check = distanceY + ((m - startX) + (m - ball[0])) ** 2; // 오른 쿠션
                distance = Math.min(distance, check);
            }
        }
        
        answer.push(distance);
    }
    
    return answer;
}