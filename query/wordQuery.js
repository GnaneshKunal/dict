const graphql = require('graphql');
const { GraphQLNonNull, GraphQLList, GraphQLString } = graphql;
const axios = require('axios');

const WordType = require('../types/wordType.js');

module.exports = {
    type: new GraphQLList(WordType),
    args: {
        word: {
            type: new GraphQLNonNull(GraphQLString),
            description: 'The word you want to search',
        }
    },
    resolve: (_, args) => {
        return axios.get(`http://api.wordnik.com/v4/word.json/${args.word}/definitions?limit=200&includeRelated=true&useCanonical=false&includeTags=false&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data)
            .catch(err => err);
    }
};