#include <vector>
using namespace std;

int bit_length(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n >>= 1;
    }
    return count;
}

int bit_length_total(vector<int> numbers) {
    int total_bits = 0;
    for (auto num : numbers) {
        total_bits += bit_length(num);
    }
    return total_bits;
}
