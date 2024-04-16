import tkinter as tk
from tkinter import ttk
import serial
dir(serial)
import threading
import os

def speak(text):
    os.system(f'say "New {text}"') # The serial text starts with "Coffee order..." so the "new" makes it say "New coffee order..."

def read_serial():
    ser = serial.Serial('/dev/cu.usbserial-0001', 115200)  # Replace with ESP32 serial port
    while True:
        line = ser.readline().decode('utf-8').strip()
        if line:
            root.after(100, add_order, line) 
            speak(line)

def add_order(order):
    orders_listbox.insert(tk.END, order)

def complete_order():
    selected_index = orders_listbox.curselection()
    if selected_index:
        orders_listbox.delete(selected_index)
       

root = tk.Tk()
root.title("Coffee Orders")

root.resizable(True, True)

orders_frame = ttk.Frame(root)
orders_frame.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)

orders_label = ttk.Label(orders_frame, text="Orders:")
orders_label.pack(side=tk.TOP, anchor=tk.W)

orders_listbox = tk.Listbox(orders_frame, width=40)  
orders_listbox.pack(side=tk.TOP, padx=5, pady=5, fill=tk.BOTH, expand=True)

complete_button = ttk.Button(orders_frame, text="Complete Order", command=complete_order)
complete_button.pack(side=tk.TOP, pady=10)

made_by_label = ttk.Label(orders_frame, text="Made by Matai Moorfield", font=("Arial", 8))
made_by_label.pack(side=tk.BOTTOM, anchor=tk.W, pady=10)

serial_thread = threading.Thread(target=read_serial)
serial_thread.start()

root.mainloop()
