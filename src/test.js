const http = require('http');

http.get("http://jsonplaceholder.typicode.com/posts/1", (response) => {
    response.on('end', () => {
        console.log('END')
    })

    response.on('data', () => {})
})