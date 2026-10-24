template<class Range> bool next_permutation(int first, int last, Range& r) {
    if (first == last) return false; // handles the empty case
    int i = first;
    ++i;
    if (i == last) return false; // handles the single element case
    i = last;
    --i; // last element in the sequence

    for (;;) {
        int ii = i--; // ii = i + 1

        if (r[i] < r[ii]) { // found two adjacent elements where the left is less than the right
            int j = last;
            while (!(r[i] < r[--j])); // finds the next element for which this predicate holds
            swap(r[i], r[j]);
            reverse(r.begin() + i, r.begin() + j);
            return true;
        }
        if (i == first) {
            reverse(r.begin() + first, r.begin() + last);
            return false;
        }
    }
}
