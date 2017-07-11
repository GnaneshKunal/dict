const graphql = require('graphql');
const { 
    GraphQLList, 
    GraphQLNonNull, 
    GraphQLString, 
    GraphQLBoolean, 
    GraphQLInt 
} = graphql;
const axios = require('axios');

const wordPhrase = require('../types/wordPhraseType');

module.exports = {
    type: new GraphQLList(wordPhrase),
    description: 'Fetch phrases for the given word.',
    args: {
        word: {
            type: new GraphQLNonNull(GraphQLString),
            description: 'The word you want to search for phrases'
        },
        useCanonical: {
            type: GraphQLBoolean,
            description: 'If true will try to return the correct word root. If false returns exactly what was requested.'
        },
        wlmi: {
            type: GraphQLInt,
            description: 'Minimum WLMI for the phrase.'
        },
        limit: {
            type: GraphQLInt,
            description: 'Maximum number of results to return.'
        }
    },
    resolve: (_, { word, useCanonical, wlmi, limit }) => {
        useCanonical = useCanonical !== undefined ? useCanonical : false;
        wlmi = wlmi !== undefined ? wlmi : 0;
        limit = limit !== undefined ? limit : 5;

        return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/phrases?limit=${limit}&wlmi=${wlmi}&useCanonical=${useCanonical}&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data)
            .catch(err => err);
    }
};