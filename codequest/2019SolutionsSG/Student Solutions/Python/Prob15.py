n = int(input())

def letter_to_num(letter):
    return ord(letter) - 96

def word_to_num(word):
    num = 0
    for letter in word:
        num += letter_to_num(letter)
    return num

def hash(index, timestamp, word, pre_hash):
    sum = pre_hash + index + timestamp + word_to_num(word)
    return (50 * sum) / 147


for i in range(n):
    hashs = [ 0 ]
    data_entries = input().split(" ")
    time_stamp = input().split(" ")
    for i in range(0, 10):
        time_stamp[i] = int(time_stamp[i])
    for i in range(1, 11):
        hashs.append(hash(i, time_stamp[i-1], data_entries[i-1], hashs[i-1]))

    print(round(hashs[10]))


        
    

    
    

    