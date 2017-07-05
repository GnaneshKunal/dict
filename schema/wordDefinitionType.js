const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString, GraphQLInt } = graphql;

const WordDefinitionType = new GraphQLObjectType({
    name: 'WordDefinition',
    fields: {
        partOfSpeech: {
            type: GraphQLString,
            description: 'The words\'s parts of speech'
        },
        text: {
            type: GraphQLString,
            description: 'The definition',
        },
        sequence: {
            type: GraphQLInt,
            description: 'The sequence number'
        }
    }
});

module.exports = WordDefinitionType;