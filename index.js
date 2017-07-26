const http = require('http');
const express = require('express');
const expressGraphQL = require('express-graphql');
const app = express();
const server = http.createServer(app);
const schema = require('./schema/schema');

require('dotenv').config();

const PORT = process.env.PORT || 8080;

app.use('/graphql', expressGraphQL({
    schema,
    graphiql: true
}));

app.get('/', (req, res) => {
    return res.send({
        Name: 'Dict',
        Author: 'Gnanesh Kunal',
        url: 'http://dict-cli.herokuapp.com/graphql',
        repositoryURL: 'https://github.com/GnaneshKunal/dict'
    });
});

server.listen(PORT, (err) => {
    if (err)
        throw err;
    /*eslint no-console: */
    console.log(`Server is is running on port: ${PORT}`);
});