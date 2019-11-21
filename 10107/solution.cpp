#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int next, index;
    vector <int> list;

    while (scanf("%d", &next) != EOF) {
        list.push_back(next);
        sort(list.begin(), list.end());
        
        index = list.size() / 2;

        if (list.size() % 2 == 0) {
            printf("%d\n", (list[index] + list[index-1]) / 2);    
        } 
        else {printf("%d\n", list[index]);}
        
    }
    return 0;
}
