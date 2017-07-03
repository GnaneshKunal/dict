const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString, GraphQLInt, GraphQLList } = graphql;
const { getWord, getExamples } = require('../src/data/');
const wordExample = require('./wordExampleType');
const WordType = new GraphQLObjectType({
    name: 'Word',
    fields: {
        text: { type: GraphQLString },
        sequence: { type: GraphQLInt },
        score: { type: GraphQLInt },
        undefined: { type: GraphQLString },
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

/*
http://api.wordnik.com/v4/word.json/test?useCanonical=false&includeSuggestions=false&api_key=a2a73e7b926c924fad7001ca3111acd55af2ffabf50eb4ae5
*/