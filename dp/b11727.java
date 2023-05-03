import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int table[] = new int[n + 2];

        table[1] = 1; table[2] = 3;

        // bottom-up
        for (int i = 3; i <= n; ++i) {
            table[i] = (table[i - 1] + table[i - 2] * 2) % 10007;
        }

        bw.write(Integer.toString(table[n]));
        bw.flush();
        bw.close();
    }
}