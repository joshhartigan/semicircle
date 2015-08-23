function Dictionary() {

  var identifiers = []
  var values      = []

  this.set = function(identifier, value) {
    identifiers.push(identifier)
    values.push(value)
  }

  this.get = function(identifier) {

    if ( identifiers.indexOf(identifier) >= 0 ) {
      return values[ identifiers.indexOf(identifier) ]
    } else {
      return null
    }

  }

  this.hasIdentifier = function(identifier) {
    return identifiers.indexOf(identifier) >= 0
  }

  this.hasValue = function(value) {
    return values.indexOf(value) >= 0
  }

}

