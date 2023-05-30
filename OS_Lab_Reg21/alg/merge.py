import random
from timeit import default_timer as timer
import matplotlib.pyplot as plt
def mergeSort(array):
    if len(array) > 1:
        r = len(array) // 2
        L = array[:r]
        M = array[r:]
        mergeSort(L)
        mergeSort(M)
        i = j = k = 0
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = M[j]
                j += 1
            k += 1
        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1
        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1
x = []
y = []
for i in range(3):
    n = int(input("\nEnter the value of n: "))
    x.append(n)
    arr = [random.randint(0, 1000) for _ in range(n)]
    print("\nThe array elements are:", arr)
    start_time = timer()
    mergeSort(arr)
    end_time = timer()
    print("Array elements after sorting:", arr)
    elapsed_time = end_time - start_time
    y.append(elapsed_time)
    print("Time taken:", elapsed_time)
plt.plot(x, y)
plt.title('Time Taken for Merge Sort')
plt.xlabel('n')
plt.ylabel('Time (seconds)')
plt.show()
