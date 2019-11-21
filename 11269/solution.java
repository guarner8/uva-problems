import java.util.PriorityQueue;
import java.io.EOFException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

class Node {
    int brief = 0;
    int work = 0;

    public Node(int brief, int work) {
        this.brief = brief;
        this.work = work;
    }
}

class SortA implements Comparator<Node> {
    public int compare(Node a, Node b) {
        return a.brief - b.brief;
    }
}

class SortB implements Comparator<Node> {
    public int compare(Node a, Node b) {
        return  b.work - a.work ;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<Node> arr = new ArrayList<Node>();
        ArrayList<Node> brr = new ArrayList<Node>();
        ArrayList<Node> crr = new ArrayList<Node>();

        int n;
        while (in.hasNext()) {
            n = in.nextInt();

            arr.clear();
            brr.clear();
            crr.clear();
            int inputA [] = new int[10000];
            for (int i = 0; i < n; i++) {
                inputA[i] = in.nextInt();
            }

            for (int i = 0; i < n; i++) {
                int x = inputA[i];
                int y = in.nextInt();

                Node next = new Node(x, y);
                if (x <= y) {
                    arr.add(next);
                } else {
                    brr.add(next);
                }
            }

            Collections.sort(arr, new SortA());
            Collections.sort(brr, new SortB());

            for (int i = 0; i < arr.size(); i++) {
                crr.add(arr.get(i));
            }
            for (int i = 0; i < brr.size(); i++) {
                crr.add(brr.get(i));
            }

            int t = crr.get(0).brief;
            int ans = crr.get(0).brief;
            for (int i = 1; i < n; i++) {
                t += crr.get(i).brief;
                ans = Math.max(crr.get(i-1).work + ans, t);
            }

            System.out.println(ans + crr.get(crr.size()-1).work);
        }

        in.close();
    }
}
