const graphql = require('graphql');
const { 
    GraphQLList, 
    GraphQLNonNull, 
    GraphQLString, 
    GraphQLBoolean, 
    GraphQLInt 
} = graphql;
const axios = require('axios');

const wordExample = require('../types/wordExampleType.js');

module.exports = {
    type: new GraphQLList(wordExample),
    description: 'Fetch examples for a given word',
    args: {
        word: {
            type: new GraphQLNonNull(GraphQLString),
            description: 'The word you want to search for examples'
        },
        includeDuplicates: {
            type: GraphQLBoolean,
            description: 'Show duplicate examples from different sources'
        },
        useCanonical: {
            type: GraphQLBoolean,
            description: 'If true will try to return the correct word root. If false returns exactly what was requested.'
        },
        skip: {
            type: GraphQLInt,
            description: 'Results to skip.'
        },
        limit: {
            type: GraphQLInt,
            description: 'Maximum number of results to return.'
        }
    },
    resolve: (_, { word, includeDuplicates, useCanonical, skip, limit }) => {
        useCanonical = useCanonical !== undefined ? useCanonical : false;
        includeDuplicates = includeDuplicates !== undefined ? includeDuplicates : false;
        skip = skip !== undefined ? skip : 0;
        limit = limit !== undefined ? limit : 5;

        return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/examples?includeDuplicates=${includeDuplicates}&useCanonical=${useCanonical}&skip=${skip}&limit=${limit}&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data.examples)
            .catch(err => err);
    }
};