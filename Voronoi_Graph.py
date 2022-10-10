import math
import matplotlib.pyplot as plt
from scipy.spatial import Voronoi, voronoi_plot_2d
import numpy
math1=[4,6,7,5,8]
csc=[3,7,8,5,8]
result1=['Fail','Fail','Pass','Fail','Pass']
l1=[]

x=int(input("Enter the marks of maths:"))
y=int(input("Enter the marks of CS:"))
k=int(input("Enter the value of k:"))

for i in range(0, len(math1)):
    d= (x-math1[i])*(x-math1[i]) + (y-csc[i])*(y-csc[i])
    l1.append([math.sqrt(d),result1[i]])
print("\nList before sorting:", str(l1))
l1.sort()
print("\nList after sorting:", str(l1))
fail=0
pass1=0 
if k > len(l1):
    k=len(l1)

for i in range(0,k):
    if l1[i][1] == 'Fail':
        fail=fail+1
    else:
        pass1=pass1+1
print("\nFinal result:")
if pass1 == fail:
    print("Tie")
elif pass1 > fail:
    print("Pass")
else:
    print("Fail")

points=numpy.array([[4,3],[6,7],[7,8],[5,5],[8,8]])
vor=Voronoi(points)
fig=voronoi_plot_2d(vor)
plt.show()