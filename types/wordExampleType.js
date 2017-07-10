const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString } = graphql;

const WordExampleType = new GraphQLObjectType({
    name: 'WordExample',
    fields: {
        text: {
            type: GraphQLString,
            description: 'Example'
        },
        title: {
            type: GraphQLString,
            description: 'Source of example'
        }
    }
});

module.exports = WordExampleType;