const graphql = require('graphql');
const { 
    GraphQLList, 
    GraphQLBoolean, 
    GraphQLString, 
    GraphQLInt,
    GraphQLNonNull
} = graphql;
const axios = require('axios');
const { includes } = require('lodash');

const wordHyphenationType = require('../types/wordHyphenationType.js');
const sourceDictionaryLib = require('../src/lib').hyphenationsSourceDictionary;

module.exports = {
    type: new GraphQLList(wordHyphenationType),
    description: 'Fetch the hyphenation for a given word.',
    args: {
        word: {
            type: new GraphQLNonNull(GraphQLString),
            description: 'The word you want to search Hyphenations for'
        },
        useCanonical: {
            type: GraphQLBoolean,
            description: 'If true will try to return a correct word root. If false returns exactly what was requested.'
        },
        sourceDictionary: {
            type: GraphQLString,
            description: 'Get from a single dictionary.'
        },
        limit: {
            type: GraphQLInt,
            description: 'Maximum number of results to return.'
        }
    },
    resolve: (_, { word, useCanonical, sourceDictionary, limit }) => {
        useCanonical = useCanonical !== undefined ? useCanonical : false;
        limit = limit !== undefined ? limit : 50;
        sourceDictionary = includes(sourceDictionaryLib, sourceDictionary) ? sourceDictionary : '';
        return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/hyphenation?useCanonical=${useCanonical}&sourceDictionary=${sourceDictionary}&limit=${limit}&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data)
            .catch(err => err);
    }
};
