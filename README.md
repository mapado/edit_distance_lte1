# edit_distance_lte1
Fast string distance function for the case where the distance is less or equal to 1.

For some use cases (e.g simple spell checking), we are only interested in knowing if the edit distance between two strings is less or equal to 1.

Computing the exact distance, for distances above 1, is then useless and potentially time consuming.

This library computes the distance between two strings and return either :
 * 0 : strings are equals
 * 1 : there is one addition / suppression / replacement
 * 7 : there are more than 1 edit operations

This is a Python binding over a C implementation inspired by the [python-Levenshtein](https://github.com/ztane/python-Levenshtein) library.

## Installation
```bash
$ pip install edit-distance-lte1
```

## Usage
```python
from edit_distance_lte1 import distance

# distance = 0
distance('mike', 'mike')
>> 0

# distance = 1
distance('mike', 'ike')
>> 1

# distance above 1 -> return max distance value (7)
distance('mike', 'remike')
>> 7
```

## Contributing

Clone the project.

Install [pipenv](https://github.com/pypa/pipenv).

Launch test with `make test`
