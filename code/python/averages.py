# short code for day 7, since I spent
# ages setting up my Jekyll page.

def list_averages(*lists):
    avg_sum = 0
    avg_len = 0
    for l in lists:
        avg_sum += list_sum(l)
        avg_len += list_len(l)
    avg_sum /= list_len(lists)
    avg_len /= list_len(lists)
    
    return [avg_sum, avg_len]

def list_sum(l):
    x = 0
    for i in l:
        x += i
    return x

def list_len(l):
    x = 0
    for i in l:
        x += 1
    return x

# TEST CASES:
a = [3, 9, 12, 6, 90, 2]
b = [17, 5, 81, 4, 55]
c = [4, 4, 90, 28]

print(list_averages(a, b, c))
# => [136, 5]

print(list_averages(a, b))
# => [142, 5]

print(list_averages(a, c))
# => [124, 5]

print(list_averages(b, c))
# => [144, 4]

