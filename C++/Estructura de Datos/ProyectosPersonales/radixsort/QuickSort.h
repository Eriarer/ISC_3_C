class QuickSort {
   private:
    int* arr;
    int length;

   public:
    QuickSort(int* arr, int length) {
        this->length = length;
        this->arr = new int[length];
        for (int i = 0; i < length; i++) {
            this->arr[i] = arr[i];
        }
    }

    void RealeseMemory() {
        delete[] arr;
    }

    int* quicksort(int left, int right) {
        int central, i, j;
        int pivote;
        central = (left + right) / 2;
        pivote = arr[central];
        i = left;
        j = right;
        int temp;

        do {
            while (arr[i] < pivote) i++;
            while (arr[j] > pivote) j--;
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j]; /*intercambia A[i] con A[j] */
                arr[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);
        if (left < j)
            quicksort(left, j); /*mismo proceso con sublista izquierda*/
        if (i < right)
            quicksort(i, right); /*mismo proceso con sublista derecha*/
        return arr;
    }
};
