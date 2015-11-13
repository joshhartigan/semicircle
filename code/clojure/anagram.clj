; i am trying to learn the functional language clojure,
; as an alternative to java which i don't enjoy writing
; in. whilst this is a short program with no algorithmic
; complexity, it's main purpose is to give me a beginning
; of a familiarity with clojure's syntax.

; namespace: anagram
(ns anagram)

; clojure code isn't usually formatted like the code
; below, but i have seperated it out onto many lines
; to fully annotate what each part of the program is
; doing.

; define function with params 's1' and 's2'
(defn anagrams? [s1, s1]
  ; check for equality between n>1 items
  (=
    ; our 2 items to check for equality are 
    ; the parameters, s1 and s2, but sorted.
    ; they are both in their own set of
    ; parentheses, so rather than 
    ; s1.sort() or sort(s1),
    ; we have a list, as always in clojure,
    ; which is why we read
    ; (sort s1).
    (sort s1) (sort s2)
  )
)
