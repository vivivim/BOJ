import java.util.*;

class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (String time : timetable)
            pq.offer(strToMinute(time));
        
        for (int i = 0; i < n; ++i) {
            int time = 540 + i * t;
            int people = 0;
            
            while (!pq.isEmpty() && pq.peek() <= time && m > people) {
                answer = pq.poll();
                ++people;
            }
            
            if (m > people) answer = time;
            else if (m == people) --answer;
        }
        
        return minuteToString(answer);
    }
    
    private int strToMinute(String time) {
        String[] splited = time.split(":");
        int hour = Integer.parseInt(splited[0]);
        int minute = Integer.parseInt(splited[1]);
        
        return hour * 60 + minute;
    }
    
    private String minuteToString(int time) {
        int hour = time / 60;
        int minute = time % 60;
        
        String strHour = hour > 9 ? Integer.toString(hour) : "0" + Integer.toString(hour);
        String strMinute = minute > 9 ? Integer.toString(minute) : "0" + Integer.toString(minute);
        
        return strHour + ":" + strMinute;
    }
}
