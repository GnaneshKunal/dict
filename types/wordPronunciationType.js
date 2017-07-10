const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString } = graphql;

const WordPronunciationType = new GraphQLObjectType({
    name: 'WordPronunciation',
    fields: {
        rawType: {
            type: GraphQLString,
            description: 'The source Type'
        },
        pronunciation: {
            type: GraphQLString,
            description: 'The pronunciation string'
        }
    }
});

module.exports = WordPronunciationType;
