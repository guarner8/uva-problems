#include <cstdio>
#include <bitset>

using namespace std;

int main() 
{
    int once, rep, start, end, step;
    bool flag;
    bitset <1000005> mins;
    scanf("%d %d", &once, &rep);
    while (once != 0 || rep != 0) 
    {
        flag = false;
        mins.reset();
        for (int i = 0; i < once; i++) 
        {
            scanf("%d %d", &start, &end);
            if (flag == true) 
            {
                continue;
            }

            for (int j = start; j < end; j++) 
            {
                if (mins[j] == 1) 
                {
                    flag = true;
                } else {
                    mins[j] = 1;
                }
            }
        }

        for (int i = 0; i < rep; i++) 
        {
            scanf("%d %d %d", &start, &end, &step);
            if (flag == true) 
            {
                continue;
            }
            bool brk = true;
            while (brk && !flag) {  
                for (int j = start; j < end; j++) 
                {
                    if (j >= 1000001) {
                        brk = false;
                        break;
                    }
                    else if (mins[j] == 1) 
                    {
                        flag = true;
                        break;
                    } else {
                        mins[j] = 1;
                    }
                }
                start += step;
                end += step;
            }
        }
        if (flag == false) {
            printf("NO CONFLICT\n");
        } else {
            printf("CONFLICT\n");
        }
        scanf("%d %d", &once, &rep);
    }
    return 0; 
}
