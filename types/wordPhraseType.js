const graphql = require('graphql');
const { GraphQLObjectType, GraphQLString, GraphQLFloat } = graphql;

const WordPhraseType = new GraphQLObjectType({
    name: 'WordPhrase',
    fields: {
        mi: {
            type: GraphQLFloat,
            description: 'The mi of the phrase.'
        },
        gram1: {
            type: GraphQLString,
            description: 'Word which is followed by gram2 (to construct the phrase).'
        },
        gram2: {
            type: GraphQLString,
            description: 'Word which follows gram1 (to construct phrase).'
        },
        wlmi: {
            type: GraphQLFloat,
            description: 'The wlmi of the phrase.'
        }
    }
});

module.exports = WordPhraseType;
