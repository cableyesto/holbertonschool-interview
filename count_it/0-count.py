#!/usr/bin/python3
"""
0-count.py
Counts occurrences of keywords in hot posts of a subreddit recursively.
"""

import re
import requests
from collections import defaultdict


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively queries the Reddit API, parses titles of hot articles,
    and prints a sorted count of given keywords (case-insensitive).

    Args:
        subreddit (str): The subreddit to query.
        word_list (list): List of keywords to count.
        after (str): Used internally for pagination.
        counts (dict): Used internally to accumulate counts across recursion.
    """
    if counts is None:
        counts = defaultdict(int)
        # Normalize words: lowercase and sum duplicates
        normalized_words = []
        for w in word_list:
            normalized_words.extend([w.lower()] * word_list.count(w))
        word_list = normalized_words

    headers = {"User-Agent": "count-words-script/1.0"}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        response = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False,
            timeout=10
        )
    except requests.RequestException:
        return

    if response.status_code != 200:
        # Invalid subreddit, rate limit, or other issues → do nothing
        return

    data = response.json()
    children = data.get("data", {}).get("children", [])
    after = data.get("data", {}).get("after")

    for post in children:
        title = post.get("data", {}).get("title", "")
        for word in word_list:
            pattern = r"\b{}\b".format(re.escape(word))
            matches = re.findall(pattern, title, flags=re.IGNORECASE)
            counts[word] += len(matches)

    if after:
        # Recursive call for next page
        count_words(subreddit, word_list, after=after, counts=counts)
    else:
        # Sort by count descending, then alphabetically
        sorted_items = sorted(
            ((w, c) for w, c in counts.items() if c > 0),
            key=lambda x: (-x[1], x[0])
        )
        for word, count in sorted_items:
            print("{}: {}".format(word, count))
