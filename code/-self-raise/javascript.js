function selfRaise(coll) {
  var array = []

  for (var i = 0; i < coll.length; i++) {
    array.push(Math.pow(coll[i], coll[i]))
  }

  return array
}
