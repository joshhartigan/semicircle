(defn self-raise [coll]
  (map #(Math/pow % %) a))

(println (self-raise [1 8 2 6 4 5]))
