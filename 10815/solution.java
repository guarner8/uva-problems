import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        SortedSet<String> dict = new TreeSet<String>();

        while (in.hasNext()) {
            String next = in.next();
            String str = "";
            for (int i = 0; i < next.length(); i++) {
                if ((next.charAt(i) >= 'a' && next.charAt(i) <= 'z') || (next.charAt(i) >= 'A' && next.charAt(i) <= 'Z')) {
                    str += next.charAt(i);
                } else {
                    if (str.length() > 0) {
                        dict.add(str.toLowerCase());
                    }
                    str = "";
                }
            }
            if (str != "") {
                dict.add(str.toLowerCase());
            }
        }

        for (String i : dict) {
            System.out.println(i);
        }

        in.close();
    }
}
