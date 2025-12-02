import java.util.*;

public class WordMath {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        String[] words = new String[n];
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            words[i] = sc.next();
            for (int j = 0; j < words[i].length(); ++j) {
                Character c = words[i].charAt(j);
                int digit = words[i].length() - j - 1;
                map.put(c, map.getOrDefault(c, 0) + (int) Math.pow(10, digit));
            }
        }

        List<Map.Entry<Character, Integer>> list = new ArrayList<>(map.entrySet());
        list.sort((a, b) -> Integer.compare(b.getValue(), a.getValue()));

        Map<Character, Integer> sortedMap = new HashMap<>();
        int frq = 9;
        for (Map.Entry<Character, Integer> m : list) {
            sortedMap.put(m.getKey(), frq--);
        }

        int answer = 0;
        int num = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                int digit = words[i].length() - j - 1;
                num += sortedMap.get(words[i].charAt(j)) * (int) Math.pow(10, digit);
            }
            answer += num;
            num = 0;
        }
        System.out.println(answer);

        sc.close();
    }
}
