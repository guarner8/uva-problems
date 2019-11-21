import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		String result;
		int input;
		
		// Car can only travel 200 miles at a time
		while ((input = in.nextInt()) != 0) {
			result = "";
			ArrayList<Integer> distances = new ArrayList<Integer>(); 
			
			

			for (int i = 0; i < input; i++) {
				distances.add(in.nextInt());
			}
			Collections.sort(distances);
			for (int i = 1; i < input; i++) {
				if (distances.get(i) - distances.get(i-1) > 200) {
					result = "IMPOSSIBLE";
				} 
			}
			
			if (input < 8 || ((1422-distances.get(input-1)) * 2) > 200) {
				System.out.println("IMPOSSIBLE");
				continue;
			}
			
			if (result == "") {
				result = "POSSIBLE";
			}
			
			System.out.println(result);
			
		}
		
		in.close();
	}
}
