import java.util.Scanner;

public class Prob17 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for(int e = 0; e < n; e++) {
            int[][] arr = new int[9][9];
            for(int i = 0; i < 9; i++) {
                String str = sc.nextLine();
                for(int j = 0; j < 9; j++) {
                    if(str.charAt(j) == '_') {
                        arr[i][j] = -1;
                    } else {
                        arr[i][j] = (int) (str.charAt(j) - '0');
                    }
                }
            }
            dfs(arr, 0, 0);

        }
    }

    public static void dfs(int[][] grid, int x, int y) {
        if(y == 9) {
            y = 0;
            x++;
            if(x == 9) {
                print(grid);
                return;
            }
        }
        if(grid[x][y] > -1) {
            dfs(grid, x, y+1);
            return;
        }

        for(int i = 1; i < 10; i++) {
            grid[x][y] = i;
            if(works(grid)) dfs(grid, x, y+1);
            grid[x][y] = -1;
        }
    }
    public static void print(int[][] sud) {
        for(int i =0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                System.out.print(sud[i][j]);
            }
            System.out.println();
        }
    }
    public static boolean works(int[][] grid) {
        for(int i = 0; i < 9; i++) {
            int[] have = new int[9];
            for(int j = 0; j < 9; j++) {
                have[j] = 0;
            }
            for(int j =0; j < 9; j++) {
                int el = grid[i][j];
                if(el < 0) continue;
                if(have[el-1] == 1) return false;
                have[el-1] = 1;
            }
        }
        for(int i = 0; i < 9; i++) {
            int[] have = new int[9];
            for(int j = 0; j < 9; j++) {
                have[j] = 0;
            }
            for(int j =0; j < 9; j++) {
                int el = grid[j][i];
                if(el < 0) continue;
                if(have[el-1] == 1) return false;
                have[el-1] = 1;
            }
        }
        int[] xs = {0, 0, 0, 3, 3, 3, 6, 6, 6};
        int[] ys = {0, 3, 6, 0, 3, 6, 0, 3, 6};
        for(int i =0 ; i < 9; i++) {
            int x = xs[i];
            int y = ys[i];
            int[] have = new int[9];
            for(int j = 0; j < 9; j++) {
                have[j] = 0;
            }
            for(int j = x; j < x+3; j++) {
                for(int k = y; k < y+3; k++) {
                    int el = grid[j][k];
                    if(el < 0) continue;
                    if(have[el-1] == 1) return false;
                    have[el-1] = 1;
                }
            }
        }
        return true;
    }
}