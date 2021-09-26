# Recommended imports for all problems
# Some problems may require more

import sys
import math
import string


CODEC = {"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9,
         "A": 10, "B": 11, "C": 12, "D": 13, "E": 14, "F": 15}


def key_parser(in_file):
    cases = []
    in_file = iter(in_file)
    case_count = int(next(in_file).rstrip())
    for _ in range(case_count):
        key_count = int(next(in_file).rstrip())
        message = next(in_file).rstrip()
        keys = []
        for __ in range(key_count):
            keys.append(next(in_file).rstrip())
        cases.append((message, keys))
    return cases


def parse_hex(hex):
    base_10 = CODEC[hex[0]] * 16
    base_10 += CODEC[hex[1]]
    return base_10


def decode(message, key):
    message = list(message)
    key = list(key)
    decode_msg = ['[']
    for i in range(0, len(message), 2):
        m_hex = message[i:i+3]
        k_hex = key[i:i+3]
        m_dec = parse_hex(m_hex)
        k_dec = parse_hex(k_hex)
        decode_msg.append(chr(m_dec ^ k_dec))
    decode_msg.append(']')
    return "".join(decode_msg)


def run(cases):
    outs = []
    for case in cases:
        message = case[0]
        keys = case[1]
        for key in keys:
            outs.append(decode(message, key))
    return outs


if __name__ == "__main__":
    lines = [l for l in sys.stdin]
    cases = key_parser(lines)
    outs = run(cases)
    for o in outs:
        print(o)
