import java.util.TreeSet;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

class Main {
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		int testCases = in.nextInt();
		for (int i = 0; i < testCases; i++) {
			TreeSet<Integer> ts = new TreeSet<Integer>();
			Queue<Integer> toErase = new LinkedList<>();
			int nums = in.nextInt();
			int max = 0;
			int count = 0;
			int toRem;
			int next;

			for (int j = 0; j < nums; j++) {
				if ( ts.add(next = in.nextInt()) ) {
					toErase.add(next);
					if (ts.size() > max) {
						max = ts.size();
					}
				} else {
					while ((toRem = toErase.poll()) != next) {
						ts.remove(toRem);
					} 
					toErase.add(next);
					ts.add(next);
				}
			}
			System.out.println(max);
		}
	}
}
