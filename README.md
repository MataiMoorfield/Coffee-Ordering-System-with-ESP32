# Coffee-Ordering-System-with-ESP32
A simple web based coffee ordering system with the ESP32 for cafés.

How to run:
Git clone the folder:
```
git clone git@github.com:MataiMoorfield/Coffee-Ordering-System-with-ESP32.git
```

Update the WiFi information for your network in the `main.ino` code. Upload the code to the ESP32. View the serial monitor to make sure it's connected to WiFi and view the local IP of the ESP32.

Run the `run.py` script while the ESP32 is plugged in. Don't run at the same time as the Arduino IDE is open.
```
cd main/Python
python run.py
```

Enter the IP of the ESP32 in a web browser. A simple ordering form opens. When the form is completed and submitted, the order will appear on the Python GUI. When selected, the order can be completed and disappears.

![Screenshot 2024-02-05 at 16 57 14](https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32/assets/138086469/063af052-8572-46fd-9aae-6a818656e237)
