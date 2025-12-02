import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AllocateMeetingRoom {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        List<int[]> meetings = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            meetings.add(new int[] {sc.nextInt(), sc.nextInt()});
        }

        int answer = 0;
        int endTime = 0;

        meetings.sort((a, b) -> {
            if (a[1] == b[1])
                return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        for (int[] m : meetings) {
            if (endTime <= m[0]) {
                ++answer;
                endTime = m[1];
            }
        }
        System.out.println(answer);
        sc.close();
    }
}
