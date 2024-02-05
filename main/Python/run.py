import tkinter as tk
import serial
import threading

def read_serial():
    ser = serial.Serial('/dev/cu.usbserial-0001', 115200)  # Replace 'COMX' with your ESP32 port
    while True:
        line = ser.readline().decode('utf-8').strip()
        if line:
            root.after(100, add_order, line)  # Use after to update GUI in the main thread

def add_order(order):
    orders_listbox.insert(tk.END, order)

def complete_order():
    selected_index = orders_listbox.curselection()
    if selected_index:
        orders_listbox.delete(selected_index)
        # Notify the user to pick up their coffee using IP (implement this)

# GUI setup
root = tk.Tk()
root.title("Coffee Orders")

# Make the Listbox resizable
orders_listbox = tk.Listbox(root, width=40)  # Set the initial width
orders_listbox.pack(pady=10, expand=True, fill=tk.BOTH)

complete_button = tk.Button(root, text="Complete Order", command=complete_order)
complete_button.pack(pady=10)

# Start serial reading thread
serial_thread = threading.Thread(target=read_serial)
serial_thread.start()

# Start GUI main loop
root.mainloop()
