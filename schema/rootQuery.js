const graphql = require('graphql');
const { 
    GraphQLObjectType
} = graphql;


const word = require('../query/wordQuery.js');
const relatedWord = require('../query/wordRelatedQuery');
const definitions = require('../query/wordDefinitionQuery');
const examples = require('../query/wordExampleQuery');
const queryType = new GraphQLObjectType({
    name: 'QueryType',
    description: 'The roor Query type',
    fields: {
        word,
        examples,
        definitions,
        relatedWord
    }
});
module.exports = queryType;
