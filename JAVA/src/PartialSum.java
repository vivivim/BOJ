import java.util.*;
import java.io.*;

public class PartialSum {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int[] seq = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i)
            seq[i] = Integer.parseInt(st.nextToken());
        int left = 0, right = 0, sum = seq[0], answer = Integer.MAX_VALUE;

        while (true) {
            if (sum >= s) {
                answer = Math.min(answer, right - left + 1);
                sum -= seq[left];
                ++left;

                if (left >= n) break;
            } else {
                ++right;
                if (right >= n) break;
                sum += seq[right];
            }
        }

        if (answer == Integer.MAX_VALUE)
            answer = 0;

        System.out.println(answer);
    }
}
