//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Searches the array anArray[first] through anArray[last]
    for a given value by using a binary search.
 @pre  0 <= first, last <= SIZE - 1, where SIZE is the
    maximum size of the array, and anArray[first] <=
    anArray[first + 1] <= ... <= anArray[last].
 @post  anArray is unchanged and either anArray[index] contains
    the given value or index == -1.
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @param target  The search key.
 @return  Either index, such that anArray[index] == target, or -1.
*/
// end binarySearch