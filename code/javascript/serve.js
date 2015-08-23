var http = require('http')
var fs = require('fs')

fs.readFile( process.argv[2], function(err, data) {
  var html = data.toString()

  http.createServer( function(request, response) {
    response.writeHead(200, { 'Content-Type': 'text/html' })
    response.end(html)
  }).listen(50210, 'localhost')

  console.log('server running at http://localhost:50210')
  console.log('have a nice life.')
})
