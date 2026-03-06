import java.io.*;
import java.util.*;

public class MakeOne3 {
    static Map<Long, Long> dp = new HashMap<>();

    private static long recur(long n) {
        if (n <= 1) return 0;
        if (dp.containsKey(n)) return dp.get(n);

        long answer = n - 1;

        answer = Math.min(answer, recur(n/2) + n%2 + 1);
        answer = Math.min(answer, recur(n/3) + n%3 + 1);

        dp.put(n, answer);
        return answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());

        System.out.println(recur(n));
    }
}
