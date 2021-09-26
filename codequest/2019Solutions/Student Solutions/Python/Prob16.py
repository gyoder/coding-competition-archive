import sys

nProbs = int(input())


for nProb in range(nProbs):
    nKeys = int(input())
    cyphertext = input().strip()


    for nKey in range(nKeys):
        key = input().strip()

        output = ""

        i = 0
        while i < len(key)-1:
            keyChunk = int(key[i:i+2].lower(), 16)
            textChunk = int(cyphertext[i:i+2].lower(), 16)

            xored= textChunk ^ keyChunk

            output += chr(xored)


            i += 2

        print(f"[{output}]")