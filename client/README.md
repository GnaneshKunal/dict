# Dict (c-client)

## Installing

Do install `libcurl-dev(debian) or libcurl-devel(redhat)` and `json-c` packages.

```
$ make all
```

## Running

```
$ ./dict
Usage: dict [options] word [other options]...
Options:
        -d      : Get word Definition
        -e      : Get word Examples
        -h      : Get word Hyphenation
        -p      : Get word Phrases
        -o      : Get word Pronunciation
        -r      : Get word Relations
        -x      : Get word of the day
Other options:
        -l={n}  : Limit the result[definitions, examples, hyphenations, phrases pronunciations]
        -uc={b} :  Use canonical[all]
        -pos={s}        : PartOfSpeech[definitions]
        -sds={s}        : SourceDictionaries[definitions]
        -it={b} :  Include Tags[definitions]
        -id={b} :  Include Duplicates[examples]
        -s={n}  :   Skip[examples]
        -sd={s} :  SourceDictionary[hyphenations, pronunciations]
        -tf={s} :  Type format[pronunciations]
        -wlmi={s}       :    wlmi[phrases]
        -lrt={s}        : limitPerRelationshipType[relations]
        -rt={s} : Relationship Types
```

## Removing

```
$ make clean
```

## Contributing

Contributions to this project are always welcome and highly encouraged.

## License

MIT License (MIT)