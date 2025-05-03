import nltk



#Task 1
para = 'Joe watied for the train. The train was late. Mary and Samantha took the bus. I looked for Mary and Samantha at the bus station.'
sent = nltk.sent_tokenize(para)
print('Sentence Tokenized: ')
print(sent)



#Task2
words = nltk.word_tokenize(para)
print('\nWords Tokenized:')
print(words)


#Task 3
sent_to_words = []
for i in sent:
    sent_to_words.append(nltk.word_tokenize(i))

print('\nWords Tokenized, Sentence Form:')
for i in sent_to_words:
    print(i)