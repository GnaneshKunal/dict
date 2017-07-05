const graphql = require('graphql');
const { GraphQLObjectType , GraphQLString, GraphQLInt, GraphQLList } = graphql;
const wordExample = require('./wordExampleType');
const wordDefinition = require('./wordDefinitionType');
const axios = require('axios');

const WordType = new GraphQLObjectType({
    name: 'Word',
    fields: {
        text: { type: GraphQLString },
        sequence: { type: GraphQLInt },
        score: { type: GraphQLInt },
        definitions: {
            type: new GraphQLList(wordDefinition),
            resolve: ({ word }) => {
                return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/definitions?limit=200&includeRelated=true&useCanonical=false&includeTags=false&api_key=${process.env.WORDNIK_API_KEY}`)
                    .then(res => res.data)
                    .catch(err => err);
            }
        },
        examples: {
            type: new GraphQLList(wordExample),
            resolve: ({ word }) => {
                return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/examples?includeDuplicates=false&useCanonical=false&skip=0&limit=5&api_key=${process.env.WORDNIK_API_KEY}`)
                    .then(res => res.data.examples)
                    .catch(err => err);
            }
        }
    }
});

module.exports = WordType;