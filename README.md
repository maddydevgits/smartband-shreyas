# smartband-shreyas
Official Repo

# Tools
1. Arduino 1.8.19

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
      <td>SDA</td>
   </tr>
</table>
