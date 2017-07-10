const { GraphQLBoolean, GraphQLString, GraphQLList, GraphQLInt } = require('graphql');
const lodash = require('lodash');
const axios = require('axios');
const wordRelated = require('../types/wordRelatedType');
const relationshipTypesLib = require('../src/lib/').wordrelationshipTypes;

module.exports = {
    type: new GraphQLList(wordRelated),
    description: 'Fetch related words for a given word',
    args: {
        word: {
            type: new GraphQLList(GraphQLString),
            description: 'The word you want to search for related words'
        },
        useCanonical: {
            type: GraphQLBoolean,
            description: 'If true will try to return the correct word root. If false returns exactly what was requested.'
        },
        relationshipTypes: {
            type: GraphQLString,
            description: 'Limits the total results per type of relationship type.'
        },
        limitPerRelationshipType: {
            type: GraphQLInt,
            description: 'Restrict to the supplied relationship types.'
        }
    },
    resolve: (_, { word, useCanonical, relationshipTypes, limitPerRelationshipType }) => {
        useCanonical = useCanonical !== undefined ? useCanonical : false;
        limitPerRelationshipType = limitPerRelationshipType !== undefined ? limitPerRelationshipType : 10;
        relationshipTypes = lodash.includes(relationshipTypesLib, relationshipTypes) ? relationshipTypes : '';
        return axios.get(`http://api.wordnik.com:80/v4/word.json/${word}/relatedWords?useCanonical=${useCanonical}&limitPerRelationshipType=${limitPerRelationshipType}&relationshipTypes=${relationshipTypes}&api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data)
            .catch(err => err);
    }
};