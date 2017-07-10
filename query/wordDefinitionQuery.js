const graphql = require('graphql');
const { GraphQLList, GraphQLNonNull, GraphQLString, GraphQLInt, GraphQLBoolean } = graphql;
const axios = require('axios');
const { includes } = require('lodash');

const wordDefinition = require('../types/wordDefinitionType');

const partOfSpeechLib = require('../src/lib').partOfSpeech;
const definitionsDictionaryLib = require('../src/lib').definitionsSourceDictionary;

module.exports = {
    type: new GraphQLList(wordDefinition),
    description: 'Fetch definitions for a given word',
    args: {
        word: {
            type: new GraphQLNonNull(GraphQLString),
            description: 'The word you want to search for definitions'
        },
        limit: {
            type: GraphQLInt,
            description: ' 	Maximum number of results to return.',
        },
        partOfSpeech: {
            type: GraphQLString,
            description: 'part-of-speech types.'
        },
        includeRelated: {
            type: GraphQLBoolean,
            description: 'Return related words with definitions.'
        },
        sourceDictionaries: {
            type: GraphQLString,
            description: 'Source dictionary to return definitions from.'
        },
        useCanonical: {
            type: GraphQLBoolean,
            description: 'If true will try to return the correct word root. If false returns exactly what was requested.'
        },
        includeTags: {
            type: GraphQLBoolean,
            description: 'Return a closed set of XML tags in response.'
        }
    },
    resolve: (_, { word, limit, partOfSpeech, includeRelated, sourceDictionaries, useCanonical, includeTags }) => {
        limit = limit !== undefined ? limit : 200;
        includeRelated = includeRelated !== undefined ? includeRelated : false;
        useCanonical = useCanonical !== undefined ? useCanonical : false;
        includeTags = includeTags !== undefined ? includeTags : false;
        sourceDictionaries = includes(definitionsDictionaryLib, sourceDictionaries) ? sourceDictionaries : '';
        partOfSpeech = includes(partOfSpeechLib, partOfSpeech) ? partOfSpeech : '';
        return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/definitions?limit=${limit}&sourceDictionaries=${sourceDictionaries}&includeRelated=${includeRelated}&partOfSpeech=${partOfSpeech}&useCanonical=${useCanonical}&includeTags=${includeTags}&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data)
            .catch(err => err);
    }
};