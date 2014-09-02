quicksort <- function(arr) {
  if (length(arr) > 1) {
    pivot <- median(arr)
    c(quicksort(arr[arr < pivot]), arr[arr == pivot], quicksort[arr[arr > pivot]])
  }
}

a <- sample(1:10,10)
a <- quicksort(a)
print(a)
