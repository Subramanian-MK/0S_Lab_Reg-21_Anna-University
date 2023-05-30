def find_max_min(arr):
    n = len(arr)
    if n == 1:
        return arr[0], arr[0]
    elif n == 2:
        if arr[0] < arr[1]:
            return arr[0], arr[1]
        else:
            return arr[1], arr[0]
    else:
        mid = n // 2
        left_min, left_max = find_max_min(arr[:mid])
        right_min, right_max = find_max_min(arr[mid:])
        return min(left_min, right_min), max(left_max, right_max)
arr = [3, 5, 1, 78, 56, 94, 23, 45]
mini, maxi = find_max_min(arr)
print("The min number is:", mini)
print("The max number is:", maxi)
