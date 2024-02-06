#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    // HTML
    String htmlContent = "<html><head><style>";
    htmlContent += "body {font-family: Arial, sans-serif; margin: 20px;}";
    htmlContent += "form {max-width: 400px; margin: auto;}";
    htmlContent += "label {display: block; margin: 10px 0;}";
    htmlContent += "select, input, textarea {width: 100%; padding: 8px; margin: 8px 0;}";
    htmlContent += "input[type='submit'] {background-color: #4CAF50; color: white;}";
    htmlContent += "textarea {width: 100%; padding: 8px; margin: 8px 0; resize: vertical;}";
    htmlContent += "</style></head><body>";
    htmlContent += "<form action='/submit' method='POST'>";
    htmlContent += "<label for='name'>Name:</label><input type='text' name='name' required>";
    htmlContent += "<label for='coffee_type'>Coffee Type:</label><select name='coffee_type' required>";
    htmlContent += "<option value='' disabled selected>Please select</option>";
    htmlContent += "<option value='Espresso'>Espresso</option>";
    htmlContent += "<option value='Double Espresso'>Double Espresso</option>";
    htmlContent += "<option value='Americano'>Americano</option>";
    htmlContent += "<option value='Long Black'>Long Black</option>";
    htmlContent += "<option value='Macchiato'>Macchiato</option>";
    htmlContent += "<option value='Long Macchiato'>Long Macchiato</option>";
    htmlContent += "<option value='Cortado'>Cortado</option>";
    htmlContent += "<option value='Breve'>Breve</option>";
    htmlContent += "<option value='Cappuccino'>Cappuccino</option>";
    htmlContent += "<option value='Flat White'>Flat White</option>";
    htmlContent += "<option value='Cafe Latte'>Cafe Latte</option>";
    htmlContent += "<option value='Mocha'>Mocha</option>";
    htmlContent += "<option value='Iced Coffee'>Iced Coffee</option>";
    htmlContent += "<option value=\"Barista's Special\">Barista's Special</option>";
    htmlContent += "</select>";
    htmlContent += "<label for='sugar'>Sugar:</label><select name='sugar' id='sugar' onchange='handleSugarChange()' required>";
    htmlContent += "<option value='' disabled selected>Please select</option>";
    htmlContent += "<option value='Sugar'>Sugar</option>";
    htmlContent += "<option value='None'>None</option>";
    htmlContent += "<option value='Honey'>Honey</option>";
    htmlContent += "</select>";
    htmlContent += "<div id='tsp_of_sugar_container'>";
    htmlContent += "<label for='tsp_of_sugar' id='tsp_label'>Tsp of Sugar:</label>";
    htmlContent += "<select name='tsp_of_sugar' id='tsp_of_sugar' required>";
    htmlContent += "<option value='' disabled selected>Please Select</option>";
    htmlContent += "<option value='0.5'>0.5</option>";
    htmlContent += "<option value='1.0'>1.0</option>";
    htmlContent += "<option value='1.5'>1.5</option>";
    htmlContent += "<option value='2.0'>2.0</option>";
    htmlContent += "<option value='2.5'>2.5</option>";
    htmlContent += "<option value='3.0'>3.0</option>";
    htmlContent += "<option value='3.5'>3.5</option>";
    htmlContent += "<option value='4.0'>4.0</option>";
    htmlContent += "<option value='4.5'>4.5</option>";
    htmlContent += "<option value='5.0'>5.0</option>";
    htmlContent += "</select>";
    htmlContent += "</div>";
    htmlContent += "<label for='size'>Size:</label><select name='size' required><option value='S'>Small</option><option value='M' selected>Medium</option><option value='L'>Large</option></select>";
    htmlContent += "<label for='milk'>Amount of Milk:</label><select name='milk' required><option value='None'>None</option><option value='S'>Small</option><option value='M' selected>Medium</option><option value='L'>Large</option></select>";
    htmlContent += "<label for='notes'>Notes:</label><textarea name='notes' rows='4'></textarea>";
    htmlContent += "<input type='submit' value='Submit Order'></form>";
    htmlContent += "</body></html>";
    htmlContent += "<script>";
    htmlContent += "function handleSugarChange() {";
    htmlContent += "    var sugarDropdown = document.getElementById('sugar');";
    htmlContent += "    var tspOfSugarContainer = document.getElementById('tsp_of_sugar_container');";
    htmlContent += "    var tspOfSugarInput = document.getElementById('tsp_of_sugar');";
    htmlContent += "    tspOfSugarContainer.style.display = (sugarDropdown.value === 'None' || sugarDropdown.value === '') ? 'none' : 'block';";
    htmlContent += "    tspOfSugarInput.required = (sugarDropdown.value !== 'None' && sugarDropdown.value !== '');";
    htmlContent += "}";
    htmlContent += "function adjustTspOfSugar(step) {";
    htmlContent += "    var tspOfSugarInput = document.getElementById('tsp_of_sugar');";
    htmlContent += "    var newValue = parseFloat(tspOfSugarInput.value) + step;";
    htmlContent += "    if (newValue >= 0.5 && newValue <= 5) {";
    htmlContent += "        tspOfSugarInput.value = newValue;";
    htmlContent += "    }";
    htmlContent += "}";
    htmlContent += "</script>";


    request->send(200, "text/html", htmlContent);
  });

  server.on("/submit", HTTP_POST, [](AsyncWebServerRequest* request) {
    String name = request->arg("name");
    String coffeeType = request->arg("coffee_type");
    String sugar = request->arg("sugar");
    float tspOfSugar = (sugar != "None") ? request->arg("tsp_of_sugar").toFloat() : 0.0;
    String size = request->arg("size");
    String milk = request->arg("milk");
    String notes = request->arg("notes");

   
    if (name.isEmpty() || size.isEmpty() || milk.isEmpty() || sugar.isEmpty() || coffeeType.isEmpty() || coffeeType == "Please select") {
      String errorMessage = "<html><body><h2>Error: Please fill in all required fields and select a valid coffee type.</h2></body></html>";
      request->send(400, "text/html", errorMessage);
    } else {
      // Submit page HTML
      String submitPageContent = "<html><head><style>";
      submitPageContent += "body {font-family: Arial, sans-serif; margin: 20px;}";
      submitPageContent += "h2 {color: #4CAF50;}";
      submitPageContent += "p {margin-top: 10px;}";
      submitPageContent += "</style></head><body>";
      submitPageContent += "<h2>Order Received! It will be delivered to " + name + "</h2>";
      submitPageContent += "<p><strong>Name:</strong> " + name + "</p>";
      submitPageContent += "<p><strong>Coffee Type:</strong> " + coffeeType + "</p>";
      submitPageContent += "<p><strong>Sugar:</strong> " + sugar + "</p>";
      submitPageContent += (sugar != "None") ? "<p><strong>Tsp of Sugar:</strong> " + String(tspOfSugar, 1) + "</p>" : "";

      submitPageContent += "<p><strong>Size:</strong> " + size + "</p>";
      submitPageContent += "<p><strong>Amount of Milk:</strong> " + milk + "</p>";
      submitPageContent += "<p><strong>Notes:</strong> " + notes + "</p>";
      submitPageContent += "</body></html>";

      // Serial
      Serial.print("Coffee Order - Name: ");
      Serial.print(name);
      Serial.print(", Coffee Type: ");
      Serial.print(coffeeType);
      Serial.print(", Sugar: ");
      Serial.print(sugar);
      Serial.print(", Tsp of Sugar: ");
      Serial.print(tspOfSugar);
      Serial.print(", Size: ");
      Serial.print(size);
      Serial.print(", Milk: ");
      Serial.print(milk);
      Serial.print(", Notes: ");
      Serial.println(notes);

      request->send(200, "text/html", submitPageContent);
    }
  });



  server.begin();
}

void loop() {
  // Your other code here
}
