def mode(array):
    count = {}
    for elem in array:
        try:
            count[elem] += 1
        except (KeyError):
            count[elem] = 1
    # get max count
    maximum = 0
    modeKey = 0
    for key in count.keys():
        if count[key] > maximum:
            maximum = count[key]
            modeKey = key
    return modeKey
    
