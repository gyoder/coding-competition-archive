// Sebastian Schagerer

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class prob02 {

    public static void main(String[] args) {
    
        try {
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            
            String usage = stdIn.readLine();

            while (false == usage.equals("0")) {
                int gal = Integer.parseInt(usage);
                int weeks = (10000 / gal);

                System.out.println(gal + " gallons per week will last " + weeks + " weeks");
                usage = stdIn.readLine();
            }
        }
        catch (IOException ioex) {
            ioex.printStackTrace();
        }
    }
}
