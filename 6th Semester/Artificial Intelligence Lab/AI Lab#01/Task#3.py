d = {'k1':[1,2,3,{'tricky':['oh','man','inception',{'target':[1,2,3,'hello']}]}]}
def find(l, element, x=[]):
    for i in range(len(l)) if type(l) == list else list(l.keys()):
        if(type(l[i]) == list or type(l[i]) == dict):
            x.append(i)
            find(l[i], element, x)
            x.pop()
        else:
            if(l[i] == element):
                x.append(i)
                print(l[i])
                print('found at', x)
                x.pop()
find(d, 'hello')