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

    public static void main(String args[]) throws IOException {
        int[][] board = new int[len][len];
        int[][] dis = new int[len][len];

        var br = new BufferedReader(new InputStreamReader(System.in));
        var input = br.readLine().split(" ");

        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);

        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < x; ++i) {
            var values = br.readLine();

            for (int j = 0; j < y; ++j) {
                board[i][j] = values.charAt(j);
            }
        }

        q.add(new Pair(0, 0));
        dis[0][0] = 1;

        while (!q.isEmpty()) {
            var cur = q.poll();

            if (cur.x == x - 1 && cur.y == y - 1) {
                System.out.println(dis[cur.x][cur.y]);

                return;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = dx[i] + cur.x;
                int ny = dy[i] + cur.y;

                if (0 > nx || 0 > ny || x <= nx || y <= ny || board[nx][ny] == '0' || dis[nx][ny] != 0) continue;

                q.add(new Pair(nx, ny));
                dis[nx][ny] = dis[cur.x][cur.y] + 1;
            }
        }
    }
}