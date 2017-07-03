const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString, GraphQLList } = graphql;

const WordExampleType = new GraphQLObjectType({
    name: 'WordExample',
    fields: {
        examples: {
            type: new GraphQLList(GraphQLString)
        }
    }
});

module.exports = WordExampleType;