from tkinter import *
from tkinter import messagebox

canvas=Tk()
canvas.geometry("400x260")
canvas.configure(bg="#154c79")
canvas.title("Login portal")

my_canvas=Canvas(canvas,bg="#154c79",width="400",height="100",bd=0,highlightthickness=0)
canvas.resizable(width=False, height=False)

#header
headline=Label(canvas,text="Login",bg="#154c79",font=('Helvetica', 20, 'bold'),fg='white').place(x=150,y=20)
my_canvas.create_line(0,70,400,70,fill="white")

#Login authentication
def authenticate():
    if username.get()=='naveen' and password.get()=='abc123':
        print("Welcome")
        exit()
    else:
        messagebox.showerror("Authentication failed","Account not found!")      

#username
usr=Label(canvas,text="Username",bg="#154c79",fg='white')
usr.place(x=40,y=100)
username=StringVar()
usr_entry=Entry(canvas,textvariable=username)
usr_entry.place(x=150,y=100)

#password 
pwd=Label(canvas,text="Password",bg="#154c79",fg='white')
pwd.place(x=40,y=150)
password=StringVar()
pwd_entry=Entry(canvas, show='*',textvariable=password)
pwd_entry.place(x=150,y=150) 

#show password checkbox
x=IntVar()
def show_pass():
    if x.get()==1:
        pwd_entry.config(show='')
    else:
        pwd_entry.config(show='*')
    
c1=Checkbutton(canvas,
    text='show password',
    variable=x,
    onvalue=1,
    offvalue=0,
    command=show_pass,
    bg="#154c79",
    fg='black',
    activebackground="#154c79",
    activeforeground="black",
    bd=0,highlightthickness=0).place(x=150,y=185)

#login button
btn=Button(canvas,
    text="Login", 
    bg="#002855",
    fg="white",
    command=authenticate,
    bd=0,highlightthickness=0)
btn.place(x=150,y=220)

my_canvas.pack()
canvas.mainloop()










