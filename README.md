# Coffee-Ordering-System-with-ESP32
A simple web based coffee ordering system with the ESP32 for cafés. Full video [here](https://www.youtube.com/watch?v=jhMNulLlHCo). 

### How it works
The ESP32 hosts a (local) basic user interface where a customer can fill out a form. The form data is sent via serial to a laptop running a Python script. The normal Python script (```run.py```) allows the barista to overview orders. The Mac script (```mac.py```) - for Macbooks, allows the Python to talk the orders as they come in. The ESP32 hosts a local website. This website can only be viewed if connected to the same WiFi connection as the ESP32 (declared in the C++).

> [!NOTE]
  > Please note, ```mac.py``` runs on MacOS and might possibly run on other operating systems, however it's uncertain. Use ```run.py``` instead.

### Uses
 - Café ordering systems
 - Parties/weddings beverage systems 

# Setup
The C++ code is uploaded to the ESP32. This code contains the form which allows users to customise their coffee order.

To start, clone the folder using Git Clone: (or download it as a ZIP)
```
git clone https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32.git
cd Coffee-Ordering-System-with-ESP32/main
```
Install the necessary libraries:
```
pip install -r requirements.txt
```
**Note:** If you are using macOS, use ```pip3```.

Update the WiFi information for your network in the ```main.ino``` code.
```
const char* ssid = "RouterName";
const char* password = "wifi_password";
```

Upload the code to the ESP32. View the serial monitor to make sure it's connected to WiFi. It will give the local IP of the ESP32. For example:
```
Connecting to WiFi...
Connected to WiFi
192.168.1.39
```
Enter the IP address to a search engine (Google Chrome, Safari, Firefox, etc.) and the order form will appear.

# Running the Python script
The Python script allows the barista/café owner to view the orders from the form in a graphic user interface.

> [!IMPORTANT]
> Don't run the Python script with the Arduino IDE open. The Python will ot be able to use the serial port as the Arduino IDE is using it. Close the serial monitor or quit Arduino IDE. Infomation about running the Python scrip is below.

If you are using macOS, use ```python3``` to run the ```mac.py```. This allows the Python to talk as the orders come in. Before running the Python script, double check the ESP32 port is correct (this can change from operating system). Use the Mac command ```ls /dev/cu.*```, Windows command ```wmic path Win32_PnPEntity where "Caption like '%(COM%'" get Caption,DeviceID```, or Linux command ```ls /dev/tty*```. It should look like ```/dev/cu.usbserial-0001```, ```COM3```, or ```/dev/ttyUSBx```.

How to run Mac python script:
```
cd Python
python3 mac.py
```

If you aren't using an Apple computer/Macbook, run the `run.py` script while the ESP32 is plugged in.
```
cd Python
python run.py
```

# Wiring and code:
**Physcial:**

C++ code on ESP32 → USB → Computer → Python → GUI

**System:**

ESP32 hosts HTML → User sumbits form → Serial via USB → Python → GUI and speech (on ```mac.py```)

# How to order:
Enter the IP of the ESP32 in a web browser. A simple ordering form opens. When the form is completed and submitted, the order will appear on the Python GUI. When selected, the order can be completed and disappears.

<img width="932" alt="Screenshot 2024-03-09 at 14 56 03" src="https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32/assets/138086469/fe8cd393-e466-4f03-9c06-627b4bd1f28a">

Above: The Pyhton GUI

Below: The web coffee ordering system

<div style="text-align: right">
  <img src="https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32/assets/138086469/063af052-8572-46fd-9aae-6a818656e237" alt="Alt text">
</div>

# Debugging
```
serial.serialutil.SerialException: [Errno 2] could not open port /dev/cu.usbserial-0001: [Errno 2] No such file or directory: '/dev/cu.usbserial-0001'
```
This bug comes from not having the EPS32 plugged in. Double check the ESP32 is plugged.

```
serial.serialutil.SerialException: [Errno 16] could not open port /dev/cu.usbserial-0001: [Errno 16] Resource busy: '/dev/cu.usbserial-0001'
```
This bug comes from having Arudino IDE or another prgram using the ESP32. Close whatever program is doing this.

If you are having difficulties, please email [matai@moorfield.co.nz](mailto:matai@moorfield.co.nz) and I'll be more than happy to help you out.

# Future updates
 - HTML user interface for handling orders and better interface for forms
 - QR code generator for ordering form
 - Making worldwide instead of local host 
 - Removing ESP32 and creating a server on a laptop
 - Barista menu for either the QR code, order form, and order handling 
