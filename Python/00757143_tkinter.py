from tkinter import Tk, Menu, filedialog
import tkinter as tk
from tkinter import ttk
def analyze():
    win = tk.Tk()
    win.title("Analyze")
    ttk.Label(win, text="開始年月    ").grid(column=0, row=0)
    ttk.Label(win, text="結束年月    ").grid(column=0, row=1)
    def show():
        print('開始年月:{:s}年 {:s}月'.format(beginyearChosen.get(),beginmonthChosen.get()))
        print('結束年月:{:s}年 {:s}月'.format(afteryearChosen.get(),aftermonthChosen.get()))
    beginyear = tk.StringVar()
    beginyearChosen = ttk.Combobox(win, width=12, textvariable=beginyear)
    startyear=[]
    for i in range(1900,2020):
        startyear.append(i)
    beginyearChosen['values'] = startyear 
    beginyearChosen.grid(column=1, row=0) 
    beginmonth = tk.StringVar()
    beginmonthChosen = ttk.Combobox(win, width=12, textvariable=beginmonth)
    startmonth=[]
    for i in range(1,13):
        startmonth.append(i)
    beginmonthChosen['values'] = startmonth 
    beginmonthChosen.grid(column=2, row=0) 
    afteryear = tk.StringVar()
    afteryearChosen = ttk.Combobox(win, width=12, textvariable=afteryear)
    endyear=[]
    for i in range(1900,2020):
        endyear.append(i)
    afteryearChosen['values'] = endyear 
    afteryearChosen.grid(column=1, row=1)
    aftermonth = tk.StringVar()
    aftermonthChosen = ttk.Combobox(win, width=12, textvariable=aftermonth)
    endmonth=[]
    for i in range(1,13):
        endmonth.append(i)
    aftermonthChosen['values'] = endmonth
    aftermonthChosen.grid(column=2, row=1)
    action = ttk.Button(win, text="Analyze!", command=show)
    action.grid(column=0, row=2)
    action = ttk.Button(win, text="Quit!", command=root.quit)
    action.grid(column=1, row=2)
root = Tk()
menu = Menu(root)
filemenu = Menu(menu)
menu.add_cascade(label="Menu", menu=filemenu)
filemenu.add_command(label="Analyze", command=analyze)
filemenu.add_command(label="Exit", command=root.quit)
root.config(menu=menu)
root.mainloop()