import java.io.*;

public class SimilarWord {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String word = br.readLine();
        int[] wordInfo = new int[26];
        int answer = 0;

        for (int i = 0; i < word.length(); ++i)
            ++wordInfo[word.charAt(i) - 'A'];

        for (int a = 1; a < n; ++a) {
            String compare  = br.readLine();
            int[] compareInfo = new int[26];
            int diff = 0;

            for (int j = 0; j < compare.length(); ++j)
                ++compareInfo[compare.charAt(j) - 'A'];

            for (int j = 0; j < 26; ++j) {
                if (wordInfo[j] == compareInfo[j]) continue;

                diff += Math.abs(wordInfo[j] - compareInfo[j]);

                if (diff > 2)
                    break ;
            }

            if (diff <= 1)
                ++answer;
            else if (diff == 2 && word.length() == compare.length())
                ++answer;
        }

        System.out.println(answer);
    }
}
