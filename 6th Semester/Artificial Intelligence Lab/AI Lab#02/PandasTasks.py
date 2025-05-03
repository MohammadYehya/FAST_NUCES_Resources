import pandas as pd

s1 = pd.Series([90, 60, 60, 45, 45], name='Duration')
s2 = pd.Series([110, 117, 103, 109, 117], name='Pulse')
s3 = pd.Series([130, 145, 135, 174, 1248], name='Maxpulse')
df = pd.DataFrame([s1, s2, s3]).T
df.to_csv('TestSheet.csv', index=False)

s4 = pd.Series([409.1, 479, 340, 282.4, 406], name='Calories')

df2 = pd.read_csv('TestSheet.csv')
df2.loc[0,'Pulse'] = 60
df2.loc[4, 'Maxpulse'] = 148
df2 = pd.concat([df2, s4], axis=1)

df2.to_csv('TestSheet.csv', index=False)

print(df)
print(df2)