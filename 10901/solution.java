import java.util.Scanner;
import java.util.ArrayDeque;
import java.util.ArrayList;

public class Main {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        
        for (int i = 0; i < numCases; i++) {
            ArrayDeque<Integer> left = new ArrayDeque<Integer>();
            ArrayDeque<Integer> right = new ArrayDeque<Integer>();

            int time = 0;
            int loadedCars = 0;
            int maxCars = in.nextInt();
            int travelTime = in.nextInt();
            int m = in.nextInt();
            
            int [] arr = new int[m + 5];

            ArrayDeque<Integer> posL = new ArrayDeque<Integer>();
            ArrayDeque<Integer> posR = new ArrayDeque<Integer>();

            // Read in cars
            for (int j = 0; j < m; j++) {
                int next = in.nextInt();
                String side = in.next();
                if (side.equals("left")) {
                    posL.add(j);
                    left.add(next);
                } else {
                    posR.add(j);
                    right.add(next);
                }
            }

            String side = "left";
            // Pop cars
            while (!left.isEmpty() || !right.isEmpty()) {
                if (side == "left") {
                    // No more cars waiting on left
                    if (left.isEmpty()) {
                        if (!right.isEmpty()) {
                            if (right.peek() < time) {
                                time += travelTime;
                                side = "right";
                            } else {
                                time = right.peek() + travelTime;
                                side = "right";
                            }
                        }
                    } 
                    // Cars still on queue
                    else {
                        while ((left.peek() <= time) && (loadedCars < maxCars)) {
                            arr[posL.pop()] = time + travelTime;
                            left.pop(); 
                            loadedCars++;
                            if (left.isEmpty())
                                break;
                        }
                        // Cars were loaded into the ferry
                        if (loadedCars > 0) {
                            time += travelTime;
                            side = "right";
                            loadedCars = 0;
                        } 
                        // There were no cars loaded into the ferry
                        else {
                            // Cars on both sides
                            if (!right.isEmpty() && !left.isEmpty()) {
                                if (right.peek() < left.peek()) {
                                    if (right.peek() < time) {
                                        time += travelTime;
                                    } else {
                                        time = right.peek() + travelTime;
                                    }
                                    side = "right";
                                } else {
                                    time = left.peek();
                                }
                            } 
                            // Cars on left side only
                            else if (!left.isEmpty()) {
                                time = left.peek();
                            } 
                            // Cars on right side only
                            else {
                                time = right.peek() + travelTime;
                                side = "right";
                            }
                        }
                    }
                }
                if (side == "right") {
                    // No more cars waiting on left
                    if (right.isEmpty()) {
                        if (!left.isEmpty()) {
                            if (left.peek() < time) {
                                time += travelTime;
                                side = "left";
                            } else {
                                time = left.peek() + travelTime;
                                side = "left";
                            }
                        }
                    } 
                    // Cars still on queue
                    else {
                        while ((right.peek() <= time) && (loadedCars < maxCars)) {
                            arr[posR.pop()] = time + travelTime; 
                            right.pop(); 
                            loadedCars++;
                            if (right.isEmpty())
                                break;
                        }
                        // Cars were loaded into the ferry
                        if (loadedCars > 0) {
                            time += travelTime;
                            side = "left";
                            loadedCars = 0;
                        } 
                        // There were no cars loaded into the ferry
                        else {
                            // Cars on both sides
                            if (!right.isEmpty() && !left.isEmpty()) {
                                if (left.peek() < right.peek()) {
                                    if (left.peek() < time)
                                        time += travelTime;
                                    else
                                        time = left.peek() + travelTime;
                                    side = "left";
                                } else {
                                    time = right.peek();
                                }
                            } 
                            // Cars on right side only
                            else if (!right.isEmpty()) {
                                time = right.peek();
                            } 
                            // Cars on left side only
                            else {
                                time = left.peek() + travelTime;
                                side = "left";
                            }
                        }
                    }
                }
           }
           for (int q = 0; q < m; q++) {
                System.out.println(arr[q]);
           }
            
            // Empty space between lines
            if (i + 1 != numCases) {
                System.out.println();
            }
        }			
        in.close();
    }
}
