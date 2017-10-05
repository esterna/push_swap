import random
import sys

nums = int(sys.argv[1])
array = random.sample(range(0, nums), nums)
for i in array:
    print i,
