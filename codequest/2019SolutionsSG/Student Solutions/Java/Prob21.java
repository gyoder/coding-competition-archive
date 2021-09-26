import java.io.*;
import java.util.*;
public class Prob21 {
  public static void main(String[] args) throws IOException {
    BufferedReader input=new BufferedReader(new InputStreamReader(System.in));  
    int n = Integer.parseInt(input.readLine());
    
    for (int i=0; i<n; i++) {
      StringTokenizer line = new StringTokenizer(input.readLine());
      int xs = Integer.parseInt(line.nextToken());
      int ys = Integer.parseInt(line.nextToken());
      int xc = Integer.parseInt(line.nextToken());
      int yc = Integer.parseInt(line.nextToken());
      int m = Integer.parseInt(line.nextToken());
      boolean seen = true;
      for (int j=0; j<m; j++) {
        line = new StringTokenizer(input.readLine());
        int xwi = Integer.parseInt(line.nextToken());
        int ywi = Integer.parseInt(line.nextToken());
        int xwf = Integer.parseInt(line.nextToken());
        int ywf = Integer.parseInt(line.nextToken());
        if (xc==xs && xwf==xwi)
          seen = seen && true;
        else if (xc==xs) {
          if (xs >= Math.min(xwi, xwf) && xs <= Math.max(xwi, xwf))
            seen = false;
          else
            System.out.println("YES");
        } else if (xwf==xwi) {
          if (xwi >= Math.min(xs, xc) && xwi <= Math.max(xs, xc))
            seen = false;
          else
            seen = seen && true;
        } else {
          double A = ((double)(yc-ys))/(xc-xs);
          double B = ((double)(ywf-ywi))/(xwf-xwi);
          double x = (ywi-(B*xwi)-ys+(A*xs))/(A-B);
          if (x >= Math.min(xs, xc) && x <= Math.max(xs, xc) && x >= Math.min(xwi, xwf) && x <= Math.max(xwi, xwf))
            seen = false;
          else
            seen = seen && true;
        }
      }
      if (seen == true)
        System.out.println("YES");
      else
        System.out.println("NO");
    }
  } 
}