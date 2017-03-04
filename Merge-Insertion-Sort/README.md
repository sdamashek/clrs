Merge-Insertion-Sort
====================

Merge sort, but fall back to insertion sort at a low enough `k` in order to minimize the effect of merge sort's overhead.

```
T(n) = {\Theta(n^2): n <= k
        T(n/2) + \Theta(n): n > k
       }
```

Solving this equation in a different way, insertion sort can sort `n/k` sublists of length `k` in `(n/k) \Theta(k^2) = \Theta(nk)` time.

Now determining the running time for the merges, each "row" of merges still merges a total of `n` elements. The number of leaves is now `n/k` instead of just `n`, so the number of rows is `lg n/k`.

Since time to merge the `n/k` sublists is then `\Theta(n lg(n/k))`, the resulting `T(n)` for Merge-Insertion-Sort is `T(n) = \Theta(nk + n lg(n/k))`.

For this running time to be the same as standard merge sort, `k` must be at most `\Theta(lg (n))`, so that `T(n) = \Theta(n lg n + n lg (n/lg n)) = \Theta(n lg n)`.

In practice, `k` should be chosen by experimentation, since it depends on the constant factors of insertion sort and merge sort. Here, it is chosen as `lg (n)`.

