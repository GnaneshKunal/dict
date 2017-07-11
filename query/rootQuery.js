const graphql = require('graphql');
const { 
    GraphQLObjectType
} = graphql;


const word = require('./wordQuery.js');
const relatedWords = require('./wordRelatedQuery');
const definitions = require('./wordDefinitionQuery');
const examples = require('./wordExampleQuery');
const pronunciations = require('./wordPronunciationQuery');
const hyphenations = require('./wordHyphenationQuery');

const queryType = new GraphQLObjectType({
    name: 'QueryType',
    description: 'The root Query type',
    fields: {
        word,
        examples,
        definitions,
        relatedWords,
        pronunciations,
        hyphenations
    }
});
module.exports = queryType;
