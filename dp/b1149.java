import java.util.*;
import java.io.IOException;

public class Main {
	private static final int len = 3;
	
    public static void main(String args[]) throws IOException {
        var sc = new Scanner(System.in);

        int n = sc.nextInt();

        int arr[][] = new int[n][len];
        int table[][] = new int[n][len];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < len; ++j) {
                int temp = sc.nextInt();

                arr[i][j] = temp;
            }
        }

        table[0][0] = arr[0][0]; table[0][1] = arr[0][1]; table[0][2] = arr[0][2]; // default set up

        for (int i = 1; i < n; ++i) {
            table[i][0] = arr[i][0] + Math.min(table[i - 1][1], table[i - 1][2]);
            table[i][1] = arr[i][1] + Math.min(table[i - 1][0], table[i - 1][2]);
            table[i][2] = arr[i][2] + Math.min(table[i - 1][0], table[i - 1][1]);
        }

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < len; ++i) {
            ans = Math.min(ans, table[n - 1][i]);
        }

        System.out.println(ans);
    }
}