# draw rainbow benzene
import turtle as t
colors = ["red","purple","green","orange","blue","violet"]
t.pen()
t.bgcolor("black")
for x in range(360):
    t.pencolor(colors[x%6])
    t.width(x//100 + 1)
    t.fd(x)
    t.lt(59)
