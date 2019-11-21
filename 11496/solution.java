import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static boolean inside(int i, int j, int k) {
		if ((j > k && j > i) || (j < k && j < i)) {
			return true;
		}
		return false;
	}
	
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		int samples, peak;
		while ((samples = in.nextInt()) != 0) {
			peak = 0;
			ArrayList<Integer> waves = new ArrayList<Integer>();

			for (int i = 0; i < samples; i++) {
				waves.add(in.nextInt());
			}
			
			for (int i = 0; i < samples; i++) {
				if (inside(waves.get(i % samples), waves.get((i+1)%samples), waves.get((i+2)%samples))) {
					peak++;
				}
			}
			System.out.println(peak);
		}
		in.close();
	}
}
