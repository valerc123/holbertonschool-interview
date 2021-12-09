#!/usr/bin/python3
""" Module that holds count it,
    recursive function that queries the Reddit API,
    parses the title of all hot articles,
    and prints a sorted count of given keywords
"""
import requests

reddit_url = 'https://api.reddit.com/r/'
aux_url = '{}/hot.json?after={}'


def recurse(subreddit, new_list=[], after=None):
    """ Method that Get list
    """
    if after is not None:
        url = reddit_url + aux_url.format(subreddit, after)
    else:
        url = reddit_url + '{}/hot.json'.format(subreddit)
    header = {'user-agent': 'mr. big'}

    result = requests.get(url, headers=header, allow_redirects=False)
    if result.status_code != 200:
        return None
    try:
        resJson = result.json()
    except Exception:
        return None

    if resJson.get('message') == 'Not Found':
        return

    elements = resJson.get('data').get('children')
    new_list += [element.get('data').get('title') for element in elements]
    after = resJson.get('data').get('after')
    if after is not None:
        return recurse(subreddit, new_list, after)
    else:
        return new_list


def print_new_words(word_list, new_list):
    """ Method that print words
    """
    new_dict = {}
    for word in word_list:
        x = 0
        for title in new_list:
            j = title.lower().split()
            if word.lower().strip() in j:
                x += j.count(word.lower().strip())

        if word.lower() in new_dict:
            new_dict[word.lower()] += x
        else:
            new_dict.update({word.lower(): x})

    for key, value in sorted(new_dict.items(), key=lambda x: (-x[1], x[0])):
        if new_dict.get(key) != 0:
            print("{}: {}".format(key, value))


def count_words(subreddit, word_list):
    """ Method that counts words
    """
    new_list = recurse(subreddit)
    if new_list is None:
        return

    print_new_words(word_list, new_list)
