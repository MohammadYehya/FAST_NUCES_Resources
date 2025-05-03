import spacy



#Task 1
nlp = spacy.load("en_core_web_sm")
doc = nlp('Wall Street Journal just published an interesting piece on crypto currencies.')
spacy.displacy.render(doc, style='dep', options={'distance':90})



#Task 2
nlp2 = spacy.blank('en')
doc = nlp2('Hello my name is Mohammad Yehya Hayati. I am a student at FAST NUCES. I am in the sixth semester.')
for i in doc:
    print(i)
