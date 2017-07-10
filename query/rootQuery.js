const graphql = require('graphql');
const { 
    GraphQLObjectType
} = graphql;


const word = require('../query/wordQuery.js');
const relatedWords = require('../query/wordRelatedQuery');
const definitions = require('../query/wordDefinitionQuery');
const examples = require('../query/wordExampleQuery');
const pronunciations = require('../query/wordPronunciationQuery');

const queryType = new GraphQLObjectType({
    name: 'QueryType',
    description: 'The roor Query type',
    fields: {
        word,
        examples,
        definitions,
        relatedWords,
        pronunciations
    }
});
module.exports = queryType;
