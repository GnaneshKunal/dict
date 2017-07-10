const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString, GraphQLList } = graphql;

const WordRelatedType = new GraphQLObjectType({
    name: 'WordRelation',
    fields: {
        relationshipType: {
            type: GraphQLString,
            description: 'The Relationship type of the given word'
        },
        words: {
            type: new GraphQLList(GraphQLString),
            description: 'Collection of related words'
        }
    }
});

module.exports = WordRelatedType;