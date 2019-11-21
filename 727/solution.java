import java.util.Scanner;
import java.util.Stack;
public class Main {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        String next, result; 
        Character popOp;

        int num = Integer.parseInt(in.nextLine());
        if (in.hasNextLine())
            next = in.nextLine();

        while (in.hasNextLine()) {
        for (int i = 0; i < num; i++) {
            result = "";
            // Stack within loop
            Stack<Character> ops = new Stack<Character>();
            next = in.nextLine();
            while (!next.equals("")) {
                if (Character.isDigit(next.charAt(0))) {
                    result += next.charAt(0); 
                } else {
                    // Check empty stack
                    if (ops.empty()) {
                        ops.push(next.charAt(0));
                    }
                    // Handle paren close
                    else if (next.charAt(0) == ')') {
                        if (!ops.empty()) {
                            popOp = ops.pop();
                            while (popOp != '(') {
                                result += popOp;
                                popOp = ops.pop();
                            }
                        }
                    }
                    // Check higher level precedence +,-.
                    else if (next.charAt(0) == '+' || next.charAt(0) == '-') {
                        if (!ops.empty()) {
                            while (ops.peek() == '/' || ops.peek() == '*') {
                                result += ops.pop();
                                if (ops.empty()) {
                                    break;
                                }
                            }
                        }
                        // Check same level precedence
                        if (!ops.empty())
                        {
                            if (ops.peek() == '+' || ops.peek() == '-')
                                result += ops.pop();
                        }
                        ops.push(next.charAt(0));
                    } 
                    // Check same level precedence
                    else if (next.charAt(0) == '/' || next.charAt(0) == '*') {
                        if (!ops.empty())
                        {   
                            if (ops.peek() == '/' || ops.peek() == '*')
                            result += ops.pop();
                        }
                        ops.push(next.charAt(0));
                    } 
                    // To push open paren
                    else {
                        ops.push(next.charAt(0));
                    }
                }
                // Check if next line is empty
                if (in.hasNextLine()) {
                    next = in.nextLine();
                } else {
                    break;
                }
            }
            // Pop end of line operators
            while (!(ops.empty())) {
                result += ops.pop();
            }
            // Print new line after output
            if (i + 1 == num)
                System.out.println(result);
            else
                System.out.println(result + "\n");
        }
    }

        in.close();
    }
}
