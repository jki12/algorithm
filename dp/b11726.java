import java.util.*;
import java.io.IOException;

public class Main {
    public static void main(String args[]) throws IOException {
        var sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int table[] = new int[n + 2]; // n = 1

        table[1] = 1; table[2] = 2;

        // bottom-up
        for (int i = 3; i <= n; ++i) {
            table[i] = (table[i - 1] + table[i - 2]) % 10007;
        }

        System.out.println(table[n]);
    }
}

// ref : https://ko.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-addition-and-subtraction