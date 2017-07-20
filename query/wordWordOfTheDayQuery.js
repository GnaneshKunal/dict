const axios = require('axios');
const wordWordOfTheDayType = require('../types/wordWordOfTheDayType');

module.exports = {
    type: wordWordOfTheDayType,
    description: 'Fetches the word of the day.',
    resolve: () => {
        return axios.get(`http://api.wordnik.com:80/v4/words.json/wordOfTheDay?api_key=${process.env.WORDNIK_API_KEY}`)
            .then(res => res.data)
            .catch(err => err);
    }
};