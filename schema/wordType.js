const graphql = require('graphql');
const { GraphQLObjectType, GraphQLNonNull, GraphQLString, GraphQLInt, GraphQLList } = graphql;
const { getWord, getExamples } = require('../src/data/');
const wordExample = require('./wordExampleType');
const axios = require('axios');

const WordType = new GraphQLObjectType({
    name: 'Word',
    fields: {
        text: { type: GraphQLString },
        sequence: { type: GraphQLInt },
        score: { type: GraphQLInt },
        examples: {
            type: new GraphQLList(wordExample),
            resolve: () => {
                return {
                    examples: getExamples
                };
            }
        }
    }
});

const queryType = new GraphQLObjectType({
    name: 'QueryType',
    description: 'The roor Query type',
    fields: {
        words: {
            type: new GraphQLList(WordType),
            resolve: () => getWord
        },
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
            resolve: () => getExamples
        },
        str: {
            type: new GraphQLList(GraphQLString),
            resolve: () => ['sadsda', 'asdsda']
        },
        str2: {
            type: wordExample, // dude check this
            resolve: () => {
                return {
                    examples: ['asdsad', 'saddsadsa'] // nesting is what you were suffering
                };
            }
        }
    }
});
module.exports = queryType;
