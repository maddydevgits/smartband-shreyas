# smartband-shreyas
Official Repo

# Tools
1. Arduino 1.8.19
2. http://ai2.appinventor.mit.edu
3. https://www.thingspeak.com

# Libraries
1. Adafruit SSD1306
2. ThingSpeak

# ESP32 Link
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

# Link to Follow for setting up ESP32 with Arduino
https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

# Steps
1. Install Libraries from Library Manager
2. Configure ESP32 in Arduino
3. Configure Hotspot with SSID: smartband and password: 1234567890
4. Press Start Button for Calibration
5. Press Stop Button to calculate the Threshold Value
6. Login into the App
7. You should able to view the Sensory Data on App
8. Click Evaluate for AI Recommendations

# Connections

# OLED Display
<table>
   <tr>
      <th>S.No</th>
      <th>Name of Pin</th>
      <th>Where it is Connected</th>
   </tr>
   <tr>
      <td>1</td>
      <td>Vcc</td>
      <td>Vin</td>
   </tr>
   <tr>
      <td>2</td>
      <td>Gnd</td>
      <td>Gnd</td>
   </tr>
   <tr>
      <td>3</td>
      <td>SCK</td>
      <td>D21</td>
   </tr>
   <tr>
      <td>4</td>
      <td>SDA</td>
      <td>D22</td>
   </tr>
</table>

# Buttons, LED, Sensor, Buzzer
<table>
   <tr>
      <th>S.No</th>
      <th>Name of Pin</th>
      <th>Where it is Connected</th>
   </tr>
   <tr>
      <td>1</td>
      <td>Start Button</td>
      <td>D2</td>
   </tr>
   <tr>
      <td>2</td>
      <td>Stop Button</td>
      <td>D5</td>
   </tr>
   <tr>
      <td>3</td>
      <td>RED LED</td>
      <td>D32</td>
   </tr>
   <tr>
      <td>4</td>
      <td>GREEN LED</td>
      <td>D33</td>
   </tr>
   <tr>
      <td>5</td>
      <td>Sensor</td>
      <td>D34</td>
   </tr>
   <tr>
      <td>6</td>
      <td>3.3V</td>
      <td>3V3</td>
   </tr>
   <tr>
      <td>7</td>
      <td>GND</td>
      <td>GND</td>
   </tr>
   <tr>
      <td>8</td>
      <td>Lo+</td>
      <td>D18</td>
   </tr>
   <tr>
      <td>9</td>
      <td>Lo-</td>
      <td>D19</td>
   </tr>
   <tr>
      <td>10</td>
      <td>Buzzer</td>
      <td>D23</td>
   </tr>
</table>
