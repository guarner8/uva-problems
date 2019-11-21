import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String result = "";
            int inputs  = in.nextInt();
           
            int a = 0;
            int b = 0;
            for (int i = 0; i < inputs; i++) {
                a = in.nextInt();
                b = in.nextInt();
                if (a < b)
                    result += "<";
                else if (a > b)
                    result += ">";
                else
                    result += "=";
                if (i + 1 < inputs)
                    result += "\n";
            }
            System.out.println(result);
    }
}
