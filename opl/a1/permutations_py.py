import sys

def permutation(n):
    def sub(i):
        # base case is when our counter i is equal to the max index
        if i == n - 1:
            print(list(a))
        else:
            for k in range(i, n):
                # Swap element at current idx k and the counter index
                a[i], a[k] = a[k], a[i]
                # Call recursively with freshly swapped elements
                sub(i + 1)
                # Swap elements again after the recursive call returns
                a[i], a[k] = a[k], a[i]

    a = list(range(1, n + 1))
    sub(0)

num = int(sys.argv[1])
permutation(num)
