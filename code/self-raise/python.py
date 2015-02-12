def self_raise(coll):
    return [n ** n for n in coll]

# test
print self_raise([1, 8, 2, 6, 4, 5])
