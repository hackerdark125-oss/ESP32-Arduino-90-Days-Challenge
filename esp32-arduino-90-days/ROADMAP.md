# 90-Day Roadmap


## Phase 1: Foundations (Days 1-14)

| Day | Topic | Goal |
|---|---|---|
| 1 | Setup Arduino IDE and ESP32 board package | Install IDE, add ESP32 boards, upload first sketch |
| 2 | Blink the onboard LED | Use pinMode and digitalWrite |
| 3 | Serial Monitor basics | Print values with Serial.begin(115200) and Serial.println |
| 4 | External LED and resistor | Wire an LED on a breadboard safely |
| 5 | Push button input | Read digitalRead with INPUT_PULLUP |
| 6 | Button debounce | Handle bouncing in software |
| 7 | Week 1 mini project: LED toggle switch | Toggle LED state with one button |
| 8 | Variables, types and functions | Write clean helper functions |
| 9 | Arrays and loops with multiple LEDs | Knight Rider chase effect |
| 10 | millis() instead of delay() | Blink without blocking |
| 11 | Non-blocking multitasking | Run two timed tasks at once |
| 12 | Serial input commands | Control LED from typed commands |
| 13 | ESP32 pinout and safe pins | Learn input-only, strapping and flash pins |
| 14 | Week 2 mini project: traffic light | State machine with millis() |

## Phase 2: Analog, PWM and Sensors (Days 15-28)

| Day | Topic | Goal |
|---|---|---|
| 15 | ADC basics: analogRead | Read a potentiometer (12-bit) |
| 16 | ADC calibration and smoothing | Average readings, map values |
| 17 | PWM with LEDC | Dim an LED with ledcWrite |
| 18 | RGB LED color mixing | Three PWM channels |
| 19 | Servo motor control | Sweep and position a servo |
| 20 | Buzzer and tones | Play simple melodies |
| 21 | Week 3 mini project: potentiometer-controlled light | Combine ADC and PWM |
| 22 | LDR light sensor | Auto night light |
| 23 | DHT22 temperature and humidity | Read and print sensor data |
| 24 | Ultrasonic distance sensor HC-SR04 | Measure distance with pulseIn |
| 25 | PIR motion sensor | Trigger events on motion |
| 26 | External interrupts | attachInterrupt with a button |
| 27 | Hardware timers | Periodic timer interrupt |
| 28 | Week 4 mini project: parking sensor | Ultrasonic plus buzzer plus LEDs |

## Phase 3: Displays and Communication (Days 29-42)

| Day | Topic | Goal |
|---|---|---|
| 29 | I2C protocol and scanner | Find devices on the bus |
| 30 | 16x2 LCD over I2C | Show text and custom characters |
| 31 | SSD1306 OLED basics | Draw text with Adafruit GFX |
| 32 | OLED graphics | Lines, rectangles, bitmaps |
| 33 | OLED animation | Bouncing ball at stable FPS |
| 34 | SPI protocol basics | Understand MOSI, MISO, SCK, CS |
| 35 | Week 5 mini project: sensor dashboard on OLED | Temp, humidity and distance |
| 36 | TFT display with TFT_eSPI | Color graphics over SPI |
| 37 | UART and Serial2 | Talk between two devices |
| 38 | SD card read and write | Log data to a file |
| 39 | RTC module DS3231 | Keep accurate time |
| 40 | Data logger | Timestamped sensor logs to SD |
| 41 | Rotary encoder | Menu navigation input |
| 42 | Week 6 mini project: menu system | Encoder plus OLED menu |

## Phase 4: WiFi, Web and IoT (Days 43-63)

| Day | Topic | Goal |
|---|---|---|
| 43 | Connect to WiFi | Station mode, status and reconnect |
| 44 | Scan WiFi networks | List SSIDs and signal strength |
| 45 | Access Point mode | Make the ESP32 its own network |
| 46 | NTP time sync | Get real time over the internet |
| 47 | HTTP GET request | Fetch data from a public API |
| 48 | Parse JSON with ArduinoJson | Read weather API data |
| 49 | Week 7 mini project: weather station | API data on OLED |
| 50 | Basic web server | Serve a simple HTML page |
| 51 | Control LED from web page | Buttons that call routes |
| 52 | Show live sensor data on web page | Auto-refresh dashboard |
| 53 | Async web server | ESPAsyncWebServer basics |
| 54 | WebSockets | Real-time two-way updates |
| 55 | SPIFFS / LittleFS | Serve files from flash |
| 56 | Week 8 mini project: home control panel | Web UI for relays and sensors |
| 57 | MQTT basics | Publish and subscribe with a broker |
| 58 | MQTT sensor publisher | Send readings to a topic |
| 59 | MQTT remote control | Subscribe and switch a relay |
| 60 | Relay module safety | Drive loads the safe way |
| 61 | Bluetooth Classic serial | Control from a phone |
| 62 | BLE basics | GATT services and characteristics |
| 63 | Week 9 mini project: BLE sensor beacon | Phone reads live sensor data |

## Phase 5: Advanced ESP32 (Days 64-77)

| Day | Topic | Goal |
|---|---|---|
| 64 | Dual core and FreeRTOS tasks | xTaskCreatePinnedToCore |
| 65 | Task priorities and delays | vTaskDelay and scheduling |
| 66 | Queues between tasks | Pass sensor data safely |
| 67 | Mutexes and semaphores | Protect shared resources |
| 68 | Preferences (NVS storage) | Save settings across reboots |
| 69 | Deep sleep and wake sources | Timer and button wakeup |
| 70 | Week 10 mini project: battery-friendly logger | Sleep, wake, log, repeat |
| 71 | Touch pins | Capacitive touch input |
| 72 | Hall sensor and internal temp | Built-in peripherals |
| 73 | OTA updates | Upload code over WiFi |
| 74 | WiFiManager captive portal | Configure WiFi without hardcoding |
| 75 | Watchdog and error handling | Make firmware robust |
| 76 | Power and battery basics | LiPo, regulators, current budget |
| 77 | Week 11 mini project: OTA-ready IoT node | Combine WiFi, MQTT, OTA, NVS |

## Phase 6: Capstone - ESP32 Racing Game (Days 78-90)

| Day | Topic | Goal |
|---|---|---|
| 78 | Capstone planning | Design, parts list and architecture |
| 79 | Display and game loop | Fixed timestep rendering |
| 80 | Player car and input | Buttons or encoder controls |
| 81 | Scrolling road | Animated road with perspective |
| 82 | Obstacles and spawning | Random traffic cars |
| 83 | Collision detection | Hitbox checks |
| 84 | Score and difficulty ramp | Speed increases over time |
| 85 | Sound effects | Buzzer engine and crash sounds |
| 86 | High score storage | Save best score in NVS |
| 87 | Polish: menus and game states | Title, play, game over |
| 88 | Optimize performance | Hit smooth 30+ FPS |
| 89 | Document and record demo | README, wiring diagram, video |
| 90 | Final review and next steps | Reflect and plan what comes next |
