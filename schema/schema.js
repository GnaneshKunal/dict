const graphql = require('graphql');
const { GraphQLSchema } = graphql;

const RootQueryType = require('../query/rootQuery');
// const mutations = require('./mutaions');

module.exports = new GraphQLSchema({
    query: RootQueryType,
    // mutation: mutations
});