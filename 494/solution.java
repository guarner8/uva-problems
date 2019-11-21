import java.util.Scanner;

class Main {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int count;
        boolean isWord;
        
        while (in.hasNextLine()) {
            String line = in.nextLine();
            String arr[] = line.split(" ");

            count = 0;
            //System.out.println(line);

            for (int i = 0; i < arr.length; i++) {
                isWord = false;
                for (int j = 0; j < arr[i].length(); j++) {
                    int q = arr[i].charAt(j);
                    if ((q > 64 && q < 91) || (96 < q && q < 123)) {
                        isWord = true;
                    } else {
                        if (isWord == true) {
                            count++;
                        }
                        isWord = false;
                    }
                }
                if (isWord == true) {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
