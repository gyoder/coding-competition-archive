// Sebastian Schagerer

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class prob08 {

    public static void main(String[] args) {
    
        try {
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            
            String line = stdIn.readLine();
            int num = Integer.parseInt(line);


            for (int l = 0; l < num; l++) {
                line = stdIn.readLine();
                int len = line.length();

                for (int c = 0; c < len; c++) {
                    for(int s = 1; s < len-c; s++) {
                        System.out.print(" ");
                    }
                    System.out.println(line.substring(0, (c+1)));
                }

                for (int c = 0; c < len; c++) {
                    System.out.println(line.substring((c+1)));
                }
                
                System.out.println();
            }
        }
        catch (IOException ioex) {
            ioex.printStackTrace();
        }
    }
}
