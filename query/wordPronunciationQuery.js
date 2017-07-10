const graphql = require('graphql');
const { 
    GraphQLList, 
    GraphQLNonNull, 
    GraphQLString, 
    GraphQLBoolean, 
    GraphQLInt 
} = graphql;
const { includes, mapKeys } = require('lodash');
const axios = require('axios');

const wordPronunciation = require('../types/wordPronunciationType.js');

const sourceDictionaryLib = require('../src/lib/').sourceDictionary;
const typeFormatLib = require('../src/lib/').typeFormat;

module.exports = {
    type: new GraphQLList(wordPronunciation),
    description: 'Fetch pronunciation for a given word',
    args: {
        word: {
            type: new GraphQLNonNull(GraphQLString),
            description: 'The word you want to search for examples'
        },
        useCanonical: {
            type: GraphQLBoolean,
            description: 'If true will try to return the correct word root. If false returns exactly what was requested.'
        },
        limit: {
            type: GraphQLInt,
            description: 'Maximum number of results to return.'
        },
        sourceDictionary: {
            type: GraphQLString,
            description: 'Get from a single dictionary'
        },
        typeFormat: {
            type: GraphQLString,
            description: ' Text pronunciation type'
        }
    },
    resolve: (_, { word, useCanonical, limit, sourceDictionary, typeFormat }) => {
        useCanonical = useCanonical !== undefined ? useCanonical : false;
        limit = limit !== undefined ? limit : 50;
        sourceDictionary = includes(sourceDictionaryLib, sourceDictionary) ? sourceDictionary : '';
        typeFormat = includes(typeFormatLib, typeFormat) ? typeFormat : '';
        return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/pronunciations?useCanonical=${useCanonical}&sourceDictionary=${sourceDictionary}&typeFormat=${typeFormat}&limit=${limit}&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => {
                return res.data.map(e => {
                    return mapKeys(e, (val, key) => {
                        if (key === 'raw')
                            return 'pronunciation';
                        return key;
                    });
                });
            })
            .catch(err => err);
    }
};
