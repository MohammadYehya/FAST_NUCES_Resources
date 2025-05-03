lst = [1,2,[3,4],[5,[100,200,['hello']],23,11],1,7]
def find(l, element, x=[]):
    for i in range(len(l)):
        if(type(l[i]) == list):
            x.append(i)
            find(l[i], element, x)
            x.pop()
        else:
            if(l[i] == element):
                x.append(i)
                print(l[i])
                print('found at', x)
                x.pop()
find(lst, 'hello')