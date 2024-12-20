#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a; 
    int b; 
    int visited_k; 
    int visited_a; 
} Box;


long long abs_distance(int x, int y) {
    return x > y ? x - y : y - x;
}


int find_nearest(Box *boxes, int n, int pos, int is_key) {
    long long min_dist = 1e18;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if ((is_key && !boxes[i].visited_k) || (!is_key && !boxes[i].visited_a)) {
            int target = is_key ? boxes[i].b : boxes[i].a;
            long long dist = abs_distance(pos, target);
            if (dist < min_dist) {
                min_dist = dist;
                idx = i;
            }
        }
    }
    return idx;
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    Box boxes[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &boxes[i].a, &boxes[i].b);
        boxes[i].visited_k = 0;
        boxes[i].visited_a = 0;
    }

    long long total_dist = 0;
    int pos = s;

    for (int i = 0; i < n; i++) {
        int nearest_k_idx = find_nearest(boxes, n, pos, 1);
        if (nearest_k_idx != -1) {
            total_dist += abs_distance(pos, boxes[nearest_k_idx].b);
            pos = boxes[nearest_k_idx].b;
            boxes[nearest_k_idx].visited_k = 1;
        }

        int nearest_a_idx = find_nearest(boxes, n, pos, 0);
        if (nearest_a_idx != -1) {
            total_dist += abs_distance(pos, boxes[nearest_a_idx].a);
            pos = boxes[nearest_a_idx].a;
            boxes[nearest_a_idx].visited_a = 1;
        }
    }

    total_dist += abs_distance(pos, s);

    printf("%lld\n", total_dist);
    return 0;
}

