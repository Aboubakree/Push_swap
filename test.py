from itertools import permutations

numbers = [1, 2, 3, 4]
perms = permutations(numbers)

for perm in list(perms):
    print(' '.join(map(str, perm)))