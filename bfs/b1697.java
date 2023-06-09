import java.io.*;
import java.util.*;

class Pair {
    public int x, sec;

    public Pair(int x, int sec) {
        this.x = x;
        this.sec = sec;
    }
}

public class Main {
    private static final int len = 100001;

    public static void main(String args[]) throws IOException {
        boolean[] vis = new boolean[len];

        var br = new BufferedReader(new InputStreamReader(System.in));
        var input = br.readLine().split(" ");

        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(x, 0));
        vis[x] = true;

        while (!q.isEmpty()) {
            var cur = q.poll();

            if (cur.x == y) {
                System.out.println(cur.sec);

                return;
            }

            int temp = cur.x - 1;
            if (0 <= temp && !vis[temp]) {
                q.add(new Pair(temp, cur.sec + 1));

                vis[temp] = true;
            }

            temp = cur.x + 1;
            if (temp <= y && !vis[temp]) {
                q.add(new Pair(temp, cur.sec + 1));

                vis[temp] = true;
            }

            temp = cur.x * 2;
            if (temp <= len && !vis[temp]) {
                q.add(new Pair(temp, cur.sec + 1));

                vis[temp] = true;
            }
        }
    }
}

// counter example : 30 59 ans : 2