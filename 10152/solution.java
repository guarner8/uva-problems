import java.util.Scanner;
import java.util.Stack;
import java.util.ArrayList;

class Main {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        String next;
        int cases = Integer.parseInt(in.nextLine());

        for (;cases != 0; cases--) {
            ArrayList ordered = new ArrayList<Integer>();
            ArrayList state = new ArrayList<String>();
            
            int num = Integer.parseInt(in.nextLine());

            for (int i = 0; i < num; i++) {
                next = in.nextLine();
                state.add(next);
            }
            for (int i = 0; i < num; i++) {
                next = in.nextLine();
                ordered.add(next);
            }

            int orderedFlag = 0;
            int curr = ordered.size() - 1;
            for (int i = ordered.size() - 1; i >= 0; i--) {
                //System.out.println(ordered.get(curr) + " : " + state.get(i));
                if (ordered.get(curr).equals(state.get(i))) {curr--;}
            }

            while (curr != -1) {
                System.out.println(ordered.get(curr));
                curr--;
            }

            // if (cases != 1) {
                System.out.println();
            
            //System.out.println(curr);

            // while (curr != -1) {
            //     for (int i = ordered.size() - 1; i >= 0; i--) {
            //         if (ordered.get(curr).equals(state.get(i))) {
            //             System.out.println()
            //             curr--;
            //             String store = (String) state.get(i);
            //             for (int k = 0; k < i; k++) {
            //                 state.add(k+1, state.get(k));
            //             }
            //             state.add(0, store);
            //             break;
            //         }
            //     }
            // }

        }
    }
}
