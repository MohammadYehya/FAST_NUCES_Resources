import matplotlib.pyplot as plt
import numpy as np



#Task 1
line1x = np.array([0,1,2,3,4,5])
line1y = np.array([0,1,2,3,4,5])
line2x = np.array([0,1,2,3,4,5])
line2y = np.array([8,7.5,7,6.5,6,5.5])

plt.plot(line1x, line1y, label = 'Line1', linestyle = '-')
plt.plot(line2x, line2y, label = 'Line2', linestyle = '--')
plt.xlabel('X-Axis')
plt.ylabel('Y-Axis')
plt.legend()
plt.title('Matplotlib Task#1')
plt.grid(True)

plt.show()


#Task 2
p = np.array([51.72, 20.69, 17.24, 10.34])
labels = ['Mortgage', 'Utilities', 'Food', 'Repairs']
plt.pie(p, labels=labels, startangle=90)
plt.title('Matplotlib Task2')
plt.show()