/* IMPORTANT OBSERVATIONS
1.If you insert a number greater than the current median,i.e, to the right of the current median,then your new median will depend
  on the next larger element than the current median and the new median will shift to the right
2. If you insert a number smaller than the current median,i.e, to the left of the current median,then your new median will depend
  on the previous smaller element than the current median and the median will shift to the left
   Hence we have to keep a track of the prev smaller and the  next larger element than the median.
   For this, we can maintain a heap,i.e, for all elements smaller than the current median we can maintain a max heap on the right
   of the median because you want an element which is smaller than median but the largest.
   For all elements greater than the current median, maintain a min heap.
->If at any point there are N+1 elements in the max heap and N elements in the min heap, then the top of the max heap will be the median
  because there are N elements smaller than the top(in max heap) and N elements larger than the top(in min heap)
->If at any point there are N elements in the max heap and N elements in the min heap, then median will be
  the average of the elements at the top of the 2 heaps
->If at any point there are N elements in the max heap and N+1 elements in the min heap,then the top of the min heap will be the median
  because there will be N elements smaller than the top(in max heap) and N elements larger than the top(in min heap)

Now,every new element will either be pushed into the max heap or the min heap depending on the balancing condition
If there are N+1 elements in the min heap and N elements in the max heap,then you should ideally push the new element in the max heap
so that both the heaps have N+1 elements
But if the new element is larger than the current median in the above case, then you will pop the top element in min heap,push it in the
max heap and then push the new element in the min heap to maintain the balance and vice versa if there are N+1 elements in the max heap
and N elements in the min heap

ALGORITHM:
1.Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain elements of higher half
  at any point of time.
2.Take initial value of median as 0.
3.For every newly read element, insert it into either max heap or min-heap and calculate the median based on the following conditions:
 ->If the size of max heap is greater than the size of min-heap and the element is less than the previous median then pop the top
  element from max heap and insert into min-heap and insert the new element to max heap else insert the new element to min-heap.
  Calculate the new median as the average of top of elements of both max and min heap.
 ->If the size of max heap is less than the size of min-heap and the element is greater than the previous median then pop the top
  element from min-heap and insert into the max heap and insert new element to min heap else insert the new element to the max heap.
  Calculate the new median as the average of top of elements of both max and min heap.
 ->If the size of both heaps is the same,then check if the current is less than the previous median or not.
   If the current element is less than the previous median then insert it to the max heap and a new median will be equal to the top
   element of max heap.
   If the current element is greater than the previous median then insert it to min-heap and new median will be equal to the top
   element of min heap.

