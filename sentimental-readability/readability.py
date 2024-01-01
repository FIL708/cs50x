# TODO

import re


def main():
    text = input("Text: ")

    letters = len(re.sub(r"[^a-zA-Z0-9]", "", text))
    words = len(text.split())
    sentences = 0

    for s in text:
        if s in [".", "!", "?"]:
            sentences += 1
    avrW = letters / words * 100
    avrS = sentences / words * 100

    index = 0.0588 * avrW - 0.296 * avrS - 15.8

    if index < 1:
        print("Before Grade 1")

    elif index > 16:
        print("Grade 16+")

    else:
        print(f"Grade {round(index)}")


main()
