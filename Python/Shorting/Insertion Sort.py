def ins_sort(ourlist):
    for x in range(1, len(ourlist)): # loop for each element starting from 1 to the length of our list
        k = ourlist[x] # element with the index x
        j = x-1 # j is the index previus the index x
        while j >=0 and k < ourlist[j]: # untill each elermnt of the list are less than their previous element my loop don't stop
                ourlist[j+1] = ourlist[j] # the elemnt indexed before the element considered is set to the next one index
                j -= 1 # I decrement index j by 1
        ourlist[j+1] = k # now k is the element in the index j+1
    return ourlist
        
ourlist = [15, 1, 9, 3]
ins_sort(ourlist)