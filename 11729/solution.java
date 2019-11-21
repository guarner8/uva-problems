import java.util.PriorityQueue;
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

class SortNodes implements Comparator<Node> {
    public int compare(Node a, Node b) {
        return b.work - a.work;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<Node> arr = new ArrayList<Node>();

        int n;
        int count = 1;
        while ((n = in.nextInt()) != 0) {
            arr.clear();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();

                Node next = new Node(x, y);
                arr.add(next);
            }

            Collections.sort(arr, new SortNodes());

            int max = 0;
            int next = 0;
            for (int i = 0; i < n; i++) {
                next += arr.get(i).brief;
                if (max < next + arr.get(i).work) 
                    max = next + arr.get(i).work;
            }

            System.out.println("Case " + count + ": " + max);
            count++;
        }

        in.close();
    }
}
