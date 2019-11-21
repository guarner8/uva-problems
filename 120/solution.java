import java.util.Scanner;
import java.util.Stack;
import java.util.Queue;
import java.util.ArrayList;
import java.util.Collections;

class Main {
    static ArrayList<Integer> flip(int j, ArrayList <Integer>pancakes) {
        Stack <Integer>pkStack = new Stack<Integer>();
        for (int i = 0; i <= j; i++) {
            pkStack.push(pancakes.get(i));
        }

        for (int i = 0; i <= j; i++) {
            pancakes.set(i, pkStack.pop());
        }

        System.out.print(pancakes.size() - j + " ");

        return pancakes;
    }
    public static void main(String [] args) {
        ArrayList <Integer>pancakes = new ArrayList<Integer>();
        ArrayList <Integer>flippedPancakes = new ArrayList<Integer>();

        Scanner in = new Scanner(System.in);

        while ( in.hasNextLine() ) {
            String next = in.nextLine();
            if (next.equals("")) {continue;}
            String arrNext [] = next.split(" ");
            if (arrNext.length == 0) {continue;}

            pancakes.clear();
            flippedPancakes.clear();
            
            for (int i = 0; i < arrNext.length; i++) {
                pancakes.add(Integer.parseInt(arrNext[i]));
                if (i != arrNext.length-1) {
                    System.out.print(pancakes.get(i) + " ");
                } else {
                    System.out.print(pancakes.get(i));
                }
                
                flippedPancakes.add(Integer.parseInt(arrNext[i]));
            }
            System.out.println();

            Collections.sort(flippedPancakes);

            for (int i = arrNext.length - 1; i >= 0; i--) {
                while (flippedPancakes.get(i) != pancakes.get(i)) {
                    
                    for (int j = i; j >= 0; j--) {
                        if (flippedPancakes.get(i) == pancakes.get(j)) {
                            if (j == 0) {
                                pancakes = flip(i, pancakes);
                            } else {
                                pancakes = flip(j, pancakes);
                                pancakes = flip(i, pancakes);
                            }
                            break;
                        }
                    }
                }
            }

            System.out.println(0);
        }   
    }
}
