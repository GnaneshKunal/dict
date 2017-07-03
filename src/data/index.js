const _ = require('lodash');

const word = [
    {
        'textProns': [],
        'sourceDictionary': 'ahd-legacy',
        'exampleUses': [],
        'relatedWords': [],
        'labels': [],
        'citations': [],
        'word': 'test',
        'sequence': '0',
        'partOfSpeech': 'noun',
        'attributionText': 'from The American Heritage® Dictionary of the English Language, 4th Edition',
        'text': "A procedure for critical evaluation; a means of determining the presence, quality, or truth of something; a trial:  a test of one's eyesight; subjecting a hypothesis to a test; a test of an athlete's endurance. ",
        'score': 0
    },
    {
        'textProns': [],
        'sourceDictionary': 'ahd-legacy',
        'exampleUses': [],
        'relatedWords': [],
        'labels': [],
        'citations': [],
        'word': 'test',
        'sequence': '1',
        'partOfSpeech': 'noun',
        'attributionText': 'from The American Heritage® Dictionary of the English Language, 4th Edition',
        'text': 'A series of questions, problems, or physical responses designed to determine knowledge, intelligence, or ability.',
        'score': 0
    }
];


var dat = {
    "examples": [
        {
            "provider": {
                "name": "wsj",
                "id": 707
            },
            "year": 2009,
            "rating": 760.8301,
            "url": "http://api.wordnik.com/v4/mid/4e8d78fb5d066e8e71a1089286295b61058966ca336617fea92af5d86e315c59",
            "word": "reduce",
            "text": "Founder Mollie Culligan says the new hire, who has connections to tanneries and vendors, has helped the label reduce per-unit costs 20%.",
            "title": "Layoffs Allow Small Firms to Attract Big-Company Refugees",
            "documentId": 24066452,
            "exampleId": 798164353
        },
        {
            "provider": {
                "name": "spinner",
                "id": 712
            },
            "year": 2010,
            "rating": 747,
            "url": "http://api.wordnik.com/v4/mid/41f11f568719a27baceac5c7b5cb360f22fc66bf6123ced7c507efb181716d8b",
            "word": "reduce",
            "text": "One other thing , we must stop using the term reduce and replace it with eliminate when referring to deficit spending.",
            "title": "msnbc.com: Top msnbc.com headlines",
            "documentId": 31055612,
            "exampleId": 155729885
        },
        {
            "provider": {
                "name": "spinner",
                "id": 712
            },
            "year": 2008,
            "rating": 745,
            "url": "http://api.wordnik.com/v4/mid/1d8123755e251f673e6624cbcf43de577e7082f213510e54ff800b3e9ba1ba35",
            "word": "reduce",
            "text": "Blog: Films with 'America' in the title reduce the country to a brand",
            "title": "the-inbetween.com",
            "documentId": 16243822,
            "exampleId": 343741042
        },
        {
            "provider": {
                "name": "simonschuster",
                "id": 722
            },
            "year": 2003,
            "rating": 532.66016,
            "url": "http://api.wordnik.com/v4/mid/81b7450d7b2917fc274624eb4684682a4f7952d90e709760defce6fd435b53c2",
            "word": "reduce",
            "text": "9 Whenever he saw them unseasonably and insolently elated, he would with a word reduce them to alarm; on the other hand, if they fell victims to a panic, he could at once restore them to confidence.",
            "title": "THE LANDMARK THUCYDIDES",
            "documentId": 32552545,
            "exampleId": 705907004
        },
        {
            "provider": {
                "name": "wordnik",
                "id": 711
            },
            "year": 2009,
            "rating": 444,
            "url": "http://api.wordnik.com/v4/mid/2d4d09e1edd7995ddc3ff2074bcc4bec4e719d0c7a8256b2801d84ee047f646a",
            "word": "reduce",
            "text": "How they believe these proposals will make gang activity reduce is beyond me.",
            "title": "Controlling Conservatives, once again out of touch with the general public… &laquo; My Liberal Democrat Political Ramblings…",
            "documentId": 30500824,
            "exampleId": 962337822
        }
    ]
};

var m = ['word', 'text', 'score', 'sequence'];

var getWord = word.map(obj => {
    const name = _.mapKeys(obj, function(val, key) {
        if (_.includes(m, key)) {
            return key;
        }
    });
    return name;
});
var  examples = {
    examples: []
} ;

const getExamples = dat.examples.map(obj => {
    const name = _.mapKeys(obj, function(val, key) {
        if (_.includes(['text'], key)) {
            return 'text';
        }
    });
    return examples.examples.push(name.text);
});
// console.log(getWord);
// console.log(getExamples);
// console.log(arr);
exports.getWord = getWord;
exports.getExamples = examples;