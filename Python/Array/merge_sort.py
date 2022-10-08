def merge_sort(unsorted_list):
   if len(unsorted_list) <= 1:
      return unsorted_list
# Find the middle point and divide it
   middle = len(unsorted_list) // 2
   left_list = unsorted_list[:middle]
   right_list = unsorted_list[middle:]

   left_list = merge_sort(left_list)
   right_list = merge_sort(right_list)
   return list(merge(left_list, right_list))

# Merge the sorted halves
def merge(left_half,right_half):
   result = []
   while len(left_half) != 0 and len(right_half) != 0:
      if left_half[0] < right_half[0]:
         result.append(left_half[0])
         left_half.remove(left_half[0])
      else:
         result.append(right_half[0])
         right_half.remove(right_half[0])
   if len(left_half) == 0:
      result = result + right_half
   else:
      result = result + left_half
   return result
unsorted_list = [70, 30, 55, 22, 67, 11, 50]
print(merge_sort(unsorted_list))