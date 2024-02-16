# Coffee-Ordering-System-with-ESP32
A simple web based coffee ordering system with the ESP32 for cafés. Full video [here](https://www.youtube.com/watch?v=jhMNulLlHCo)

> [!NOTE]
> This is a system I'm currently developing for cafés to handle orders, both food and drinks.

> [!IMPORTANT]
> This is a in-progress porject. It's not fully completed and will be updated.

## How to run

Clone the folder:
```
git clone https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32.git
```
Install the necessary libraries:
```
pip install -r requirements.txt
```
Update the WiFi information for your network in the `main.ino` code. Upload the code to the ESP32. View the serial monitor to make sure it's connected to WiFi and view the local IP of the ESP32.

> [!TIP]
> Don't run the Python script with tthe Arduino IDE open

Run the `run.py` script while the ESP32 is plugged in.
```
cd main/Python
python run.py
```

Enter the IP of the ESP32 in a web browser. A simple ordering form opens. When the form is completed and submitted, the order will appear on the Python GUI. When selected, the order can be completed and disappears.

![Screenshot 2024-02-06 at 13 25 45](https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32/assets/138086469/8d18f029-6507-4e84-b749-aecffd2eb4bd)

Above: The Pyhton GUI

Below: The web coffee ordering system

<div style="text-align: right">
  <img src="https://github.com/MataiMoorfield/Coffee-Ordering-System-with-ESP32/assets/138086469/063af052-8572-46fd-9aae-6a818656e237" alt="Alt text">
</div>
