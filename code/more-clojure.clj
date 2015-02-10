;; generate a random integer up to 10
(def my-num (rand-int 10))

;; create a list of the number 10, 5 times
(def tens (repeat 5 10))

;; create a list of 5 random integers up to 10
(def my-randoms (map rand-int (repeat 5 10)))

;; get the sum of a list of 5 random integers up to 10
(def sum (apply + (map rand-int (repeat 5 10))))

;; write a function to return the sum of a list of
;; $length random integers up to $limit
(defn rand-sum [length limit]
  (apply + (map rand-int (repeat length limit))))

;; use the function
(def another-sum (rand-sum 5 10))
