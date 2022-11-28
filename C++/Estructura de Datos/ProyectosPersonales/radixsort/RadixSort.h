#include <math.h>

#include <List>
#include <iostream>
#include <numeric>
#include <vector>

class RadixSort {
   private:
    int* arr;
    int length;
    int max;
    int numDigits;

    void countSort(int* arr, int n, int exp) {
        int* output = new int[n];  // output array
        int i, count[10] = {0};

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual
        //  position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (i = 0; i < n; i++)
            arr[i] = output[i];
        delete[] output;
    }

    void RadixSortMSDRecursive(size_t lo, size_t hi, size_t depth, int max, bool showArray) {
        // radix and base calculations
        const int RADIX = 10;

        int pmax = floor(log(max + 1) / log(RADIX));

        size_t base = pow(RADIX, pmax - depth);

        // count digits
        std::vector<size_t> count(RADIX, 0);

        for (size_t i = lo; i < hi; ++i) {
            size_t r = arr[i] / base % RADIX;
            count[r]++;
        }

        // inclusive prefix sum
        std::vector<size_t> bkt(RADIX, 0);
        std::partial_sum(count.begin(), count.end(), bkt.begin());

        // mark bucket boundaries
        for (size_t i = 0; i < bkt.size(); ++i) {
            if (bkt[i] == 0) continue;
        }
        int aux;
        // reorder items in-place by walking cycles
        for (size_t i = 0, j; i < (hi - lo);) {
            while ((j = --bkt[(arr[lo + i] / base % RADIX)]) > i) {
                aux = arr[lo + i];
                arr[lo + i] = arr[lo + j];
                arr[lo + j] = aux;
            }
            i += count[(arr[lo + i] / base % RADIX)];
        }

        // no more depth to sort?
        if (depth + 1 > pmax) return;

        // recurse on buckets
        size_t sum = lo;
        if (showArray) {
            printArray();
        }

        for (size_t i = 0; i < RADIX; ++i) {
            if (count[i] <= 1) continue;
            RadixSortMSDRecursive(sum, sum + count[i], depth + 1, max, showArray);
            sum += count[i];
        }
    }

    int GetMaxNumber() {
        int max = arr[0];
        for (int i = 0; i < length; i++) {
            if (max < arr[i]) max = arr[i];
        }
        return max;
    }

    int GetNumDigit(int num) {
        if (num) {
            return 1 + GetNumDigit(num / 10);
        }
        return 0;
    }

   public:
    RadixSort(int* arr, int length) {
        this->length = length;
        this->arr = new int[length];
        for (int i = 0; i < length; i++) {
            this->arr[i] = arr[i];
        }
        max = 0;
        numDigits = 0;
    }

    void RealeseMemory() {
        delete[] arr;
    }

    int* GetArray() {
        return arr;
    }

    void printArray() {
        cout << " [";
        for (size_t i = 0; i < length; i++) {
            cout << arr[i] << (i < (length - 1) ? ", " : "");
        }
        cout << "]" << endl;
    }

    int* RadixSortLSD1(bool showArray = false) {
        // radix and base calculations
        const int RADIX = 10;
        max = GetMaxNumber();
        numDigits = GetNumDigit(max);
        int pmax = ceil(log(max + 1) / log(RADIX));  // veces que va a repetir el procedidmiento

        for (int p = 0; p < pmax; ++p) {
            size_t base = pow(RADIX, p);

            // count digits and copy data
            std::vector<size_t> count(RADIX, 0);
            std::vector<int> copy(length);

            for (size_t i = 0; i < length; ++i) {
                copy[i] = arr[i];
                size_t r = arr[i] / base % RADIX;
                count[r]++;
            }

            // exclusive prefix sum
            std::vector<size_t> bkt(RADIX + 1, 0);
            std::partial_sum(count.begin(), count.end(), bkt.begin() + 1);

            // redistribute items back into array (stable)
            for (size_t i = 0; i < length; ++i) {
                size_t r = copy[i] / base % RADIX;
                arr[bkt[r]++] = copy[i];
            }
            if (showArray) {
                printArray();
            }
        }
        return arr;
    }

    int* RadixSortLSD2(bool showArray = false) {
        numDigits = GetNumDigit(GetMaxNumber());
        int m, p, index, temp, count;
        list<int> pocket[10];  // radix of decimal number is 10
        for (int i = 0; i < numDigits; i++) {
            m = pow(10, i + 1);
            p = pow(10, i);
            for (int j = 0; j < length; j++) {
                temp = arr[j] % m;
                index = temp / p;  // find index for pocket array
                pocket[index].push_back(arr[j]);
            }
            count = 0;
            for (int j = 0; j < 10; j++) {
                // delete from linked lists and store to array
                while (!pocket[j].empty()) {
                    arr[count] = pocket[j].front();
                    pocket[j].erase(pocket[j].begin());
                    count++;
                }
            }
            if (showArray) {
                printArray();
            }
        }
        return arr;
    }

    int* RadixSortLSD3(bool showArray = false) {
        max = GetMaxNumber();
        for (long long exp = 1; max / exp > 0; exp *= 10) {
            countSort(arr, length, exp);
            if (showArray) {
                printArray();
            }
        }
        return arr;
    }

    int* RadixSortMSD4(bool showArray = false) {
        max = GetMaxNumber();
        RadixSortMSDRecursive(0, length, 0, max, showArray);
        return arr;
    }
};
