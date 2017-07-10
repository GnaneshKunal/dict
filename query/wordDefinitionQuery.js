const graphql = require('graphql');
const { GraphQLList, GraphQLString } = graphql;
const axios = require('axios');

const wordDefinition = require('../types/wordDefinitionType');

module.exports = {
    type: new GraphQLList(wordDefinition),
    description: 'Fetch definitions for a given word',
    args: {
        word: {
            type: new GraphQLList(GraphQLString),
            description: 'The word you want to search for definitions'
        }
    },
    resolve: (_, { word }) => {
        return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/definitions?limit=200&includeRelated=true&useCanonical=false&includeTags=false&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data)
            .catch(err => err);
    }
};