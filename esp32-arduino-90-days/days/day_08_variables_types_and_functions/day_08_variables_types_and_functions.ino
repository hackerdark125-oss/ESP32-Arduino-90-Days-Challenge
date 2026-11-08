// Day 8: Variables, data types and functions
// Board: ESP32-WROOM-32
// Goal: Store different kinds of data and organize code with helper functions.

const char* PROJECT_NAME = "ESP32 Day 8";
const int SAMPLE_COUNT = 4;
const float readings[SAMPLE_COUNT] = {24.5, 26.0, 25.5, 27.0};

bool projectReady = true;
char statusCode = 'A';
unsigned long bootTimeMs = 0;

// Prints a heading using a function with a parameter.
void printHeading(const char* heading) {
  Serial.println();
  Serial.println("==============================");
  Serial.println(heading);
  Serial.println("==============================");
}

// Returns a calculated value (float).
float calculateAverage(const float values[], int count) {
  if (count <= 0) {
    return 0.0;
  }

  float total = 0.0;

  for (int i = 0; i < count; i++) {
    total += values[i];
  }

  return total / count;
}

// Returns text based on a float parameter.
const char* describeTemperature(float temperatureC) {
  if (temperatureC < 20.0) {
    return "Cool";
  } else if (temperatureC <= 26.0) {
    return "Comfortable";
  }

  return "Warm";
}

// Demonstrates void functions: they perform an action but return no value.
void printProjectStatus() {
  Serial.print("Project: ");
  Serial.println(PROJECT_NAME);

  Serial.print("Ready: ");
  Serial.println(projectReady ? "true" : "false");

  Serial.print("Status code: ");
  Serial.println(statusCode);
}

void printReadingSummary() {
  float average = calculateAverage(readings, SAMPLE_COUNT);

  Serial.print("Number of readings (int): ");
  Serial.println(SAMPLE_COUNT);

  Serial.print("Average temperature (float): ");
  Serial.print(average, 2);
  Serial.println(" C");

  Serial.print("Description: ");
  Serial.println(describeTemperature(average));
}

void setup() {
  Serial.begin(115200);
  delay(500); // Gives the Serial Monitor time to connect.

  bootTimeMs = millis();

  printHeading("VARIABLES AND DATA TYPES");
  printProjectStatus();

  Serial.print("Boot time (unsigned long): ");
  Serial.print(bootTimeMs);
  Serial.println(" ms");

  printHeading("FUNCTIONS AND CALCULATIONS");
  printReadingSummary();

  printHeading("DAY 8 COMPLETE: DEMO FINISHED");
}

void loop() {
  // No repeated work is needed for this one-time learning demo.
}
