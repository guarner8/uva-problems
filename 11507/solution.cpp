#include <cstdio>
#include <iostream>
#include <string>

int main() {
    int length;
    std::string result, in;
    char input[5];

    scanf("%d", &length);
    while (length != 0) {
        result = "+x";

        for (int i = 0; i < length-1; i++) {
           scanf("%s", input);
           in = input;
           if (in != "No") {
               if (in == "+y") {
 
                   if (result == "+x")
                       result = "+y";
                   else if (result =="-x")
                       result = "-y";
                   else if (result == "+y")
                       result = "-x";
                   else if (result == "-y")
                       result = "+x";
               
               } else if (in == "-y") {
                
                   if (result == "+x")
                       result = "-y";
                   else if (result == "-x")
                       result = "+y";
                   else if (result == "+y")
                       result = "+x";
                   else if (result == "-y")
                       result = "-x";

               } else if (in == "+z") {

                   if (result == "+x")
                       result = "+z";
                   else if (result == "-x")
                       result = "-z";
                   else if (result == "+z")
                       result = "-x";
                   else if (result == "-z")
                       result = "+x";


               } else {
                    
                   if (result == "+x")
                       result = "-z";
                   else if (result == "-x")
                       result = "+z";
                   else if (result == "+z")
                       result = "+x";
                   else if (result == "-z")
                       result = "-x";

               }
           }
        }
        
        printf("%s\n", result.c_str());
        scanf("%d", &length);
    }
    
    return 0;
}
