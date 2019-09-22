import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

heatmap = list()
with open("output") as output:
	for line in output:
		num_str = line.split()
		nums = [int(n) for n in num_str] 
		heatmap.append(nums)

# x = list(range(1, len(heatmap[0]) + 1))
x = list(range(1, len(heatmap[0]) + 1))
y = list(range(1, len(heatmap) + 1))
y.reverse()

print(x)
print(y)

x, y = np.meshgrid(x, y)

heatmap = np.array(heatmap)

plt.pcolormesh(x, y, heatmap)
plt.colorbar()
plt.show()