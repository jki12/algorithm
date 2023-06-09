import java.io.*;
import java.util.*;

class Pair {
    public int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    private static final int len = 500;

    public static int[] dx = { 0, 0, 1, -1 };
    public static int[] dy = { 1, -1, 0, 0 };
    public static int count, max;

    public static void main(String args[]) throws IOException {
        int[][] board = new int[len][len];
        boolean[][] vis = new boolean[len][len];

        var br = new BufferedReader(new InputStreamReader(System.in));
        var input = br.readLine().split(" ");

        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);

        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < x; ++i) {
            var values = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray(); // string array to int array.

            assert (values.length == y);

            for (int j = 0; j < y; ++j) {
                board[i][j] = values[j];
            }
        }

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {

                if (board[i][j] == 1 && !vis[i][j]) {
                    int temp = 0; // temp size.

                    count++;

                    q.add(new Pair(i, j));
                    vis[i][j] = true;

                    while (!q.isEmpty()) {
                        var cur = q.poll();

                        temp++;

                        for (int k = 0; k < 4; ++k) {
                            int nx = dx[k] + cur.x;
                            int ny = dy[k] + cur.y;

                            if (0 > nx || 0 > ny || x <= nx || y <= ny || board[nx][ny] == 0 || vis[nx][ny]) continue;

                            q.add(new Pair(nx, ny));
                            vis[nx][ny] = true;
                        }
                    }

                    max = Math.max(max, temp);
                }
            }
        }

        System.out.printf("%d %d", count, max);
    }
}
