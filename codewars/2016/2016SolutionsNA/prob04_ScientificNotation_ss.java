// Sebastian Schagerer

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class prob04 {

    public static void main(String[] args) {
    
        try {
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            
            String line = stdIn.readLine();

            while (false == line.contains("0 0")) {
                String[] split = line.split(" ");
                double base = Double.parseDouble(split[0]);
                int exp = Integer.parseInt(split[1]);
                double ans = Math.round((base * Math.pow(10, exp)) * 100) / 100.00;

                System.out.println(String.format("%2.2f", ans));
                line = stdIn.readLine();
            }
        }
        catch (IOException ioex) {
            ioex.printStackTrace();
        }
    }
}
