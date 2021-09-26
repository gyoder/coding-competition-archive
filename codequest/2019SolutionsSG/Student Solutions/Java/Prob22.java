package ins;

import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.util.function.*;
import java.math.*;

public class Prob22 {

    static double sizeDisk;
    static ArrayList<inFile> files = new ArrayList<>();
    static final Date NOW = new Date();
    static final class inFile {

        public String filename;
        double daysOld;
        double size;

        public inFile(String in) {
            filename = in.split(" ")[4];
            String date = in.split(" ")[0];
            int day = Integer.parseInt(date.split("/")[0]);
            int month = Integer.parseInt(date.split("/")[1]);
            int year = Integer.parseInt(date.split("/")[2]);
            debug("Y" + year + "M" + month + "D" + day);
            Date fNow = new Date(year-1900, month-1, day);
            long diff = NOW.getTime()-fNow.getTime();
            diff /= 1000;
            diff /= 60;
            diff /= 60;
            diff /= 24;
            daysOld = diff;
            if(in.split(" ")[2].equals("PM"))daysOld-=0.5;
            size = Double.parseDouble(in.split(" ")[3])/1000.0;
        }
    }

    static <T> void debug(T g) {
        //System.out.println(g);
    }

    public static void main(String[] args) throws IOException {
        Input br = Input.getEnv(Prob22.class.getResourceAsStream("Prob22.in.txt"));
        int T = br.i();
        while (T-- > 0) {
            String inLine = br.r();
            sizeDisk = Double.parseDouble(inLine.split(" ")[1])*1000;
            int T2 = Integer.parseInt(inLine.split(" ")[0]);
            files.clear();
            while (T2-- > 0) {
                files.add(new inFile(br.r()));
            }
            Collections.sort(files,(a,b)->{
                double ascore = a.size * a.daysOld;
                double bscore = b.size * b.daysOld;
                return (int)((-ascore+bscore)*100000);
            });
            double mbcount = 0;
            boolean skip = false;
            for(int i = 0; i < files.size(); i++){
                if(skip)break;
                inFile a = files.get(i);
                mbcount += a.size;
                if(mbcount > sizeDisk*0.25)skip = true;
                double dd = a.size * a.daysOld;
                dd = Math.round(dd*1000.0)/1000.0;
                System.out.printf("%s %.3f\n",a.filename,dd);
            };
        }
    }

    static public class Input extends BufferedReader {

        private Input(String j) throws FileNotFoundException {
            super(new FileReader(new File(j)));
        }

        private Input(InputStream i) {
            super(new InputStreamReader(i));
        }

        public int i() throws IOException {
            return Integer.parseInt(this.readLine());
        }

        public double d() throws IOException {
            return Double.parseDouble(this.readLine());
        }

        public String r() throws IOException {
            return this.readLine();
        }

        public static Input getEnv(String filename) throws FileNotFoundException {
            try {
                if (System.getenv("localhost-id").equals("home")) {
                    return new Input(filename);
                } else {
                    throw new IllegalArgumentException("remote pc detected");
                }
            } catch (NullPointerException | SecurityException e) {
                return new Input(System.in);
            }
        }

        public static Input getEnv(InputStream filename) throws FileNotFoundException {
            try {
                if (System.getenv("localhost-id").equals("home")) {
                    return new Input(filename);
                } else {
                    throw new IllegalArgumentException("remote pc detected");
                }
            } catch (NullPointerException | SecurityException e) {
                return new Input(System.in);
            }
        }
    }
}
