import java.util.*;

class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        List<long[]> logs = new ArrayList<>();
        List<Long> times = new ArrayList<>();
        
        for (String line : lines) {
            String[] splited = line.split(" ");
            String[] time = splited[1].split(":");
            long during = (long) (Double.parseDouble(splited[2].substring(0, splited[2].length()-1)) * 1000);
            long sec = Long.parseLong(time[0]) * 3600000 + Long.parseLong(time[1]) * 60000 + (long) (Double.parseDouble(time[2]) * 1000);
            
            logs.add(new long[] {sec - during + 1, sec});
            times.add(sec);
            if (sec - during + 1 > 0)
	            times.add(sec - during + 1);
        }
        
        for (Long time : times) {
            long end = time + 999;
            int ct = 0;
            
            for (long[] log : logs) {
                if (log[0] <= end && log[1] >= time)
                    ++ct;
            }
            answer = Math.max(answer, ct);
        }
        
        return answer;
    }
}
