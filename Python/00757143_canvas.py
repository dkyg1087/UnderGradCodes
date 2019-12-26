from tkinter import *
canvas_width = 800
canvas_height =800
master = Tk()
canvas = Canvas(master, 
           width=canvas_width, 
           height=canvas_height)
canvas.pack()
img = PhotoImage(file="tkinter_canvas.png")
canvas.create_image(0,0, anchor=NW, image=img)
canvas.create_line(70, 170, 350, 170, fill="red", width=3)
mainloop()