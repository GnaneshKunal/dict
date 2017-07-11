const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString, GraphQLInt } = graphql;

const WordHyphenationType = new GraphQLObjectType({
    name: 'WordHtphenation',
    fields: {
        text: {
            type: GraphQLString,
            description: 'Split word'
        },
        type: {
            type: GraphQLString,
            description: 'Usage'
        },
        seq: {
            type: GraphQLInt,
            description: 'Sequence number.'
        }
    }
});

module.exports = WordHyphenationType;