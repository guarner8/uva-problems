import java.util.Scanner;

class Main {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);

        int cases = in.nextInt();
        for (int i = 0; i < cases; i++) {
            int contestants = in.nextInt();
            int weights [] = new int[contestants];
            int l = contestants / 2 + 1;
            int sum = 0;
            
            for (int j = 0; j < contestants; j++) {
                weights[j] = in.nextInt();
                sum += weights[j];
            }
            
            long [] dp = new long[sum+5];
            dp[0] = 1L;

            for (int q = 0; q < contestants; q++) {
                for (int j = sum; j > weights[q] - 1; j--) {
                    dp[j] |= (dp[j-weights[q]]) << 1;
                }
            }

            int min = 0;
            int max = Integer.MAX_VALUE;

            for (int q = 0; q < dp.length; q++) {
                // Check 0 to half of the contestants
                for (int j = 0; j < l + 1; j++) { 
                    // The number of people j can form this sum // Difference of teams is less or equal to than one.
                    if ((dp[q] & (1L << j)) != 0L && Math.abs(2 * j - contestants) <= 1) {  
                        // Check if the difference is there
                        if (Math.abs(sum - 2 * q) < max - min) {
                            min = Math.min(sum - q, q);
                            max = Math.max(sum - q, q);
                        }
                    }
                }
            }

            System.out.println(min + " " + max);
            if (i!=cases - 1) {
                System.out.println();
            }
        }
    }
}
