class Solution {
public:
   void heapify(vector<int>& a, int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;

        if (largest == i) break;

        swap(a[i], a[largest]);
        i = largest;
    }
}
vector<int> sortArray(vector<int>& a) {
    int n = a.size();

    // Build a max-heap (start from the last non-leaf node)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(a, n, i);

    // Repeatedly move the max to the end and shrink the heap
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);
        heapify(a, end, 0);
    }
   return a; 
}
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna