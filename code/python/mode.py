def mode(array):
    count = {}
    for elem in array:
        try:
            count[elem] += 1
        except (KeyError):
            count[elem]  = 1
    return count.keys()[ count.values().index( max(count.values()) ) ]

# test
print mode([1, 2, 4, 2, 1, 0, 4, 1]) # => 1
