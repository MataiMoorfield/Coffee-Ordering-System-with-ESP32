# Coffee-Ordering-System-with-ESP32
A simple web based coffee ordering system with the ESP32 for cafés. Full video [here](https://www.youtube.com/watch?v=jhMNulLlHCo). 

The ESP32 hosts a basic user interface which a customer can fill out a form. The form data is sent via serial to a laptop running a Python script. The normal Python (```run.py```) allows the barista to oview orders. The Mac (```mac.py```) - for Macbooks, allows the Python to talk the orders as they come in. Please note, ```mac.py``` runs on MacOS and might possibly run on other operating systems, however it's uncertain.

> [!NOTE]
> Please note, ```mac.py``` runs on MacOS and might possibly run on other operating systems, however it's uncertain.

# Setup

Clone the folder using Git Clone: (or download it as a ZIP)
```
git clone https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32.git
```
Install the necessary libraries:
```
pip install -r requirements.txt
```
Update the WiFi information for your network in the ```main.ino``` code. Upload the code to the ESP32. View the serial monitor to make sure it's connected to WiFi and view the local IP of the ESP32. For example, 
```
const char* ssid = "RouterName";
const char* password = "wifi1234567";
```
# Running the Python script
> [!IMPORTANT]
> Don't run the Python script with the Arduino IDE open. The Python will ot be able to use the serial port as the Arduino IDE is using it. Close the serial monitor or quit Arduino IDE. Infomation about running the Python scrip is below.

If you own a Mac, run the ```mac.py```. This allows the Python to talk as the orders come in
```
cd main/Python
python mac.py
```

If you don't, run the `run.py` script while the ESP32 is plugged in.
```
cd main/Python
python run.py
```

# Wiring and code:
**Physcial**
C++ code on ESP32 → USB → Computer → Python → GUI

**System:**
ESP32 hosts HTML → User sumbits form → Serial via USB → Python → GUI and speech (on ```mac.py```)

# How to order:
Enter the IP of the ESP32 in a web browser. A simple ordering form opens. When the form is completed and submitted, the order will appear on the Python GUI. When selected, the order can be completed and disappears.

![Screenshot 2024-02-06 at 13 25 45](https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32/assets/138086469/8d18f029-6507-4e84-b749-aecffd2eb4bd)

Above: The Pyhton GUI

Below: The web coffee ordering system

<div style="text-align: right">
  <img src="https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32/assets/138086469/063af052-8572-46fd-9aae-6a818656e237" alt="Alt text">
</div>

# Extras
If you are having diffuculties, please email [matai@moorfield.co.nz](mailto:matai@moorfield.co.nz) and I'll be more than happy to help you out.
