def radixSort(inputArray, base = None):
    """Sort elements by powers using buckets to store lists based on integer columns"""    
    if base is None:
      base = 10  ## For decimals
    
    ## Check for the non negative number as this method is only applicable for non negative numbers
    assert len({i <= 0 for i in inputArray}) == 1, 'Non negative numbers in the list'
        
    n = 0
    max_digit = len(str(max(inputArray)))  # find max number and get length of digits 
    

    while max_digit > n:
        bucket = [[] for _ in range(10)]        # create buckets (2D array), 10 is used as we are using decimal and distinct value of last digit is 10
        for i in inputArray:
            bucket[i//(base**n)%10].append(i)   # put corrensponding numbers in bucket
        index = 0
        for i in range(len(bucket)):       # loop through bucket
            
            stage_two = bucket[i]          # find lists of numbers in bucket
            for nums in stage_two:
                inputArray[index] = nums     # add sorted list back into original list
                index += 1
        n += 1     # increasing the power of n

    return inputArray
  
## Terst Case
assert radixSort([170, 45, 75, 90, 2, 802, 2, 66]) == [2, 2, 45, 66, 75, 90, 170, 802], "The radix sort failed"
