(ns zx.core
  (:require [quil.core :as q]
            [quil.middleware :as m]))

(defn setup []
  (q/frame-rate 30)
  ; the initial program state:
  ;  * :size    - the size of the rectangle to be drawn
  ;  * :growing - is the rectangle growing (true) or
  ;               shrinking (false)?
  ;  * :speed   - how many pixels the size of the rectangle
  ;               changes per update
  {:size 50
   :growing true
   :speed 2})

(defn update-state [state]
  (if (:growing state)
    (if (> (:size state) 99)
      {:size (- (:size state) (:speed state))
       :growing false
       :speed (:speed state)}
      {:size (+ (:size state) (:speed state))
       :growing true
       :speed (:speed state)})
    (if (< (:size state) 2)
      {:size (+ (:size state) (:speed state))
       :growing true
       :speed (:speed state)}
      {:size (- (:size state) (:speed state))
       :growing false
       :speed (:speed state)})))

(defn draw-state [state]
  ; fill grey
  (q/background 225)
  ; rgb value for fill color
  (q/fill 200 0 0)
  ; draw rect
  (let [rect-size (- 250 (/ (:size state) 2))]
    (q/rect rect-size rect-size (:size state) (:size state))))

(q/defsketch zx
  :title "zx"
  :size [500 500]
  :setup setup
  :update update-state
  :draw draw-state
  ; functional mode middleware for quil
  :middleware [m/fun-mode])
