// Sebastian Schagerer

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class prob15 {


    char[] F = new char[]{'G','G','G','G'};
    char[] L = new char[]{'O','O','O','O'};
    char[] R = new char[]{'R','R','R','R'};
    char[] B = new char[]{'B','B','B','B'};
    char[] U = new char[]{'W','W','W','W'};
    char[] D = new char[]{'Y','Y','Y','Y'};

    public prob15() {
 
        try {
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            
            String line = stdIn.readLine();

            //printCube();

            System.out.println("Start");
            printFace(F);
            System.out.println();

            while (false == line.equals(".")) {
                
                switch (line.charAt(0)) {

                    case 'F':
                       char tl = F[0];
                       F[0] = F[2];
                       F[2] = F[3];
                       F[3] = F[1];
                       F[1] = tl;
                       char temp = L[1];
                       char temp2 = L[3];
                       L[1] = D[0];
                       L[3] = D[1];
                       D[0] = R[2];
                       D[1] = R[0];
                       R[2] = U[3];
                       R[0] = U[2];
                       U[3] = temp;
                       U[2] = temp2;
                        break;
                    case 'B':
                       tl = B[0];
                       B[0] = B[1];
                       B[1] = B[3];
                       B[3] = B[2];
                       B[2] = tl;
                       temp = L[0];
                       temp2 = L[2];
                       L[0] = U[1];
                       L[2] = U[0];
                       U[0] = R[1];
                       U[1] = R[3];
                       R[1] = D[3];
                       R[3] = D[2];
                       D[3] = temp;
                       D[2] = temp2;
                        break;
                    case 'L':
                        tl = L[0];
                        L[0] = L[2];
                        L[2] = L[3];
                        L[3] = L[1];
                        L[1] = tl;
                        temp = B[1];
                        temp2 = B[3];
                        B[1] = D[2];
                        B[3] = D[0];
                        D[2] = F[2];
                        D[0] = F[0];
                        F[2] = U[2];
                        F[0] = U[0];
                        U[2] = temp;
                        U[0] = temp2;
                        break;
                    case 'R':
                        tl = R[0];
                        R[0] = R[2];
                        R[2] = R[3];
                        R[3] = R[1];
                        R[1] = tl;
                        temp = F[1];
                        temp2 = F[3];
                        F[1] = D[1];
                        F[3] = D[3];
                        D[1] = B[2];
                        D[3] = B[0];
                        B[2] = U[1];
                        B[0] = U[3];
                        U[1] = temp;
                        U[3] = temp2;
                        break;
                    case 'U':
                        tl = U[0];
                        U[0] = U[2];
                        U[2] = U[3];
                        U[3] = U[1];
                        U[1] = tl;
                        temp = F[0];
                        temp2 = F[1];
                        F[0] = R[0];
                        F[1] = R[1];
                        R[0] = B[0];
                        R[1] = B[1];
                        B[0] = L[0];
                        B[1] = L[1];
                        L[0] = temp;
                        L[1] = temp2;
                        break;
                    case 'D':
                        tl = D[0];
                        D[0] = D[2];
                        D[2] = D[3];
                        D[3] = D[1];
                        D[1] = tl;
                        temp = L[2];
                        temp2 = L[3];
                        L[2] = B[2];
                        L[3] = B[3];
                        B[2] = R[2];
                        B[3] = R[3];
                        R[2] = F[2];
                        R[3] = F[3];
                        F[2] = temp;
                        F[3] = temp2;
                        break;
                    default:
                        break;
                }

                System.out.println(line);
                printFace(F);

                //printCube();
                System.out.println();
                line = stdIn.readLine();
            }
        }
        catch (IOException ioex) {
            ioex.printStackTrace();
        }

    }

    private void printFace(char[] face) {
        System.out.println(face[0] + " " + face[1]);
        System.out.println(face[2] + " " + face[3]);
    }

    private void printCube() {
        System.out.println();
        printFace(U);
        System.out.println(L[0] + " " + L[1] + " " + F[0] + " " + F[1] + " " + R[0] + " " + R[1] + " " + B[0] + " " + B[1]);
        System.out.println(L[2] + " " + L[3] + " " + F[2] + " " + F[3] + " " + R[2] + " " + R[3] + " " + B[2] + " " + B[3]);
        printFace(D);
        System.out.println();
    }

    public static void main(String[] args) {
        new prob15();
    }
}
