# from itertools import permutations

# numbers = [1, 2, 3, 4, 5]
# perms = permutations(numbers)

# for perm in list(perms):
#     print(' '.join(map(str, perm)))

import random

# Define the range of numbers you want to generate (e.g., from 1 to 1000)
start_range = -10004
end_range = 10020

# Generate 100 random non-repeating numbers within the specified range
random_numbers = random.sample(range(start_range, end_range + 1), 500)

for number in random_numbers:
    print(number, end=" ")


# -72 437 352 -715 316 178 852 -961 397 690 -752 270 -909 527 -189 82 232 -389 935 0