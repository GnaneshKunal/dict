const graphql = require('graphql');
const { GraphQLObjectType , GraphQLString, GraphQLInt } = graphql;

const WordType = new GraphQLObjectType({
    name: 'Word',
    fields: {
        text: { type: GraphQLString },
        sequence: { type: GraphQLInt },
        score: { type: GraphQLInt }
    }
});

module.exports = WordType;