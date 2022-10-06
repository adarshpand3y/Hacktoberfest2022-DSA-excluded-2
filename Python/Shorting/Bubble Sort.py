def bubble_sort(ourlist): # I create my function bubble_sort with the argument called ourlist
    b=len(ourlist)-1 # for every list, I will have a minus 1 iteration
    for x in range(b): # for each element in the range of b, I check if they are ordered or not
        for y in range(b-x): 
            if ourlist[y]>ourlist[y+1]: # if one element is greater than the nearest elemnt in the list
                ourlist[y],ourlist[y+1]=ourlist[y+1],ourlist[y] # I have to swap the elemnts, in other words
                                                          # I exchange the position of the two elements
        return ourlist
    
ourlist=[15,1,9,3]
bubble_sort(ourlist)