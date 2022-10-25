
def bubble_sort(arr, simulation=True):
    def swap(i, j):
        arr[i], arr[j] = arr[j], arr[i]

    n = len(arr)
    swapped = True
    
    iteration = 0
    if simulation:
        print("iteration",iteration,":",*arr)
    x = -1
    while swapped:
        swapped = False
        x = x + 1
        for i in range(1, n-x):
            if arr[i - 1] > arr[i]:
                swap(i - 1, i)
                swapped = True
                if simulation:
                    iteration = iteration + 1
                    print("iteration",iteration,":",*arr)
                    
    return arr

def main():
    array = [1,5,8,5,150,44,4,3,6] #static inputs
    result = bubble_sort(array)
    print(result)
    
if __name__=="__main__":
    main()
