; this function will take 2 numbers, and a string
; representing a basic mathematical operand
; (i.e. "+", "-", "/" or "*"), and it will return
; the result of the given expression.

; namespace: evaluate
(ns eva)

; as in my previous clojure program (anagram.clj),
; the code below isn't formatted to clojure convention,
; but is written in a way that allows my annotation.

; params:
;     'x' and 'y': integers to operate with
;     'op':        the chosen operand.
(defn evaluate [x, op, y]
  ; equality is checked with polish notation
  ; (e.g. [OPERAND] [VARIABLE] [VARIABLE])
  (if (= op "+")
    (+ x y) ; this statement will be evaluated
            ; and returned.
  )
  (if (= op "-")
    (- x y)
  )
  (if (= op "*")
    (* x y)
  )
  (if (= op "/")
    (/ x y)
  )  
) ; end (evaluate x op y)
         
