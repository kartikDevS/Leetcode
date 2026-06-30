#include <stdio.h>
#include <stdbool.h>

// Helper function: Can we paint all boards within 'max_time' limit using 'k' painters?
bool canPaint(long long max_time, int* boards, int n, int k) {
    int painters_used = 1;
    long long current_workload = 0;
    
    for (int i = 0; i < n; i++) {
        // If a single board is larger than our target time, it's immediately impossible
        if (boards[i] > max_time) {
            return false;
        }
        
        if (current_workload + boards[i] <= max_time) {
            current_workload += boards[i]; // Keep adding boards to the current painter
        } else {
            painters_used++; // Allocate to the next painter
            current_workload = boards[i]; // New painter starts with this board
            
            if (painters_used > k) {
                return false; // Ran out of painters
            }
        }
    }
    return true;
}

int paintersPartition(int* boards, int n, int k) {
    long long left = 0;
    long long right = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > left) {
            left = boards[i]; // 'left' bound is the maximum single board length
        }
        right += boards[i];   // 'right' bound is the total sum of all boards
    }
    
    long long ans = right;
    
    // Binary Search on the Answer
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canPaint(mid, boards, n, k)) {
            ans = mid;         // 'mid' time works, record it
            right = mid - 1;   // Try to find a smaller maximum time
        } else {
            left = mid + 1;    // 'mid' is too tight, we need more time per painter
        }
    }
    
    return (int)ans;
}