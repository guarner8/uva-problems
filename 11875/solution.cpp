#include <cstdio>

int main() {
    int test, members, nxt;
    bool visited;

    scanf("%d", &test);	
    for (int i = 0; i < test; i++) {
        scanf("%d", &members);
		visited = false;
		for (int j = 0; j < members; j++) {
	    	scanf("%d", &nxt);
	    	if (j >= (members / 2) && visited == false) {
				visited = true;
				printf("Case %d: %d\n", i+1, nxt);
	    	}
    	}
    }
}
