const graphql = require('graphql');
const { 
    GraphQLObjectType, 
    GraphQLNonNull, 
    GraphQLString, 
    GraphQLList
} = graphql;
const wordExample = require('../types/wordExampleType');
const wordDefinition = require('../types/wordDefinitionType');
const axios = require('axios');
const WordType = require('../types/wordType');

const relatedWordQuery = require('../querys/relatedWordQuery');

const queryType = new GraphQLObjectType({
    name: 'QueryType',
    description: 'The roor Query type',
    fields: {
        word: {
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
        },
        examples: {
            type: new GraphQLList(wordExample),
            description: 'Fetch examples for a given word',
            args: {
                word: {
                    type: new GraphQLNonNull(GraphQLString),
                    description: 'The word you want to search for examples'
                }
            },
            resolve: (_, { word }) => {
                return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/examples?includeDuplicates=false&useCanonical=false&skip=0&limit=5&api_key=${process.env.WORDNIK_API_KEY}`)
                    .then(res => res.data.examples)
                    .catch(err => err);
            }
        },
        definitions: {
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
        },
        relatedWord: relatedWordQuery
    }
});
module.exports = queryType;
