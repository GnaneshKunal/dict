const http = require('http');
const express = require('express');
const expressGraphQL = require('express-graphql');
const morgan = require('morgan');
const app = express();
const server = http.createServer(app);
const schema = require('./schema/schema');

require('dotenv').config();

const PORT = process.env.PORT || 8080;

app.use(morgan('dev'));
app.use('/graphql', expressGraphQL({
    schema,
    graphiql: true
}));

server.listen(PORT, (err) => {
    if (err)
        throw err;
    /*eslint no-console: */
    console.log(`Server is is running on port: ${PORT}`);
});