import math
import os
import random
import re
import sys
def birthdayCakeCandles(ar):
    # Write your code here
    count = 0 
    maxHeight = max(ar)
    for i in ar:
        if i == maxHeight:
            count += 1
    return count
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    candles_count = int(input().strip())
    candles = list(map(int, input().rstrip().split()))
    result = birthdayCakeCandles(candles)
    fptr.write(str(result) + '\n')
    fptr.close()
