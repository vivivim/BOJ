package JAVA;

import java.util.Scanner;

public class hap_of_numbers2 {
    static int n, m, dst = 0;
    static int[] num = new int[10000];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            num[i] = sc.nextInt();
        }
        int start = 0;
        int end = 0;
        int hap = num[0];
        while (start < n && end < n) {
            if (hap < m) {
                ++end;
                if (end < n)
                    hap += num[end];
            } else {
                if (hap == m)
                    ++dst;
                hap -= num[start];
                ++start;
                if (start > end) {
                    if (start < n) {
                        hap = num[start];
                        ++end;
                    }
                }
            }
        }
        System.out.println(dst);
        sc.close();
    }
}
