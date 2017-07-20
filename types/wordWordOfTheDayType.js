const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString, GraphQLList } = graphql;

const wordExampleType = require('./wordExampleType');
const wordDefinitionType = require('./wordDefinitionType');

const WordWordOfTheDayType = new GraphQLObjectType({
    name: 'WordOfTheDay',
    fields: {
        word: {
            type: GraphQLString,
            description: 'The day word.'
        },
        publishDate: {
            type: GraphQLString,
            description: 'The date on which the word was listed as the "word of the day".'
        },
        examples: {
            type: new GraphQLList(wordExampleType),
            description: 'The examples of the word.'
        },
        definitions: {
            type: new GraphQLList(wordDefinitionType),
            description: 'The definitions of the word.'
        }
    }
});

module.exports = WordWordOfTheDayType;